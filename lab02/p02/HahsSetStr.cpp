#include <iostream>

#include "HashSetStr.hpp"

HashSetStr::~HashSetStr() {
    for (auto head : mBuckets) {
        for (Node *p = head; p != nullptr;) {
            Node *t = p;
            p = p->mNext;
            delete t;
        }
    }
}
bool HashSetStr::insert(const std::string &key) {
    std::size_t index = defaultHashFunc(key) % mBuckets.size();

    for (Node *p = mBuckets[index]; p != nullptr; p = p->mNext) {
        if (p->mData == key) {
            return false;
        }
    }

    if (mSize == mBuckets.size()) {
        rehash();
    }

    mBuckets[index] = new Node(key, mBuckets[index]);
    ++mSize;

    return true;
}

void HashSetStr::print() const {
    for (std::size_t i = 0; i < mBuckets.size(); i++) {
        std::cout << i << ":";
        for (Node *p = mBuckets[i]; p != nullptr; p = p->mNext) {
            std::cout << " " << p->mData;
        }
        std::cout << std::endl;
    }
}

bool HashSetStr::erase(const std::string &key) {
    std::size_t index = defaultHashFunc(key) % mBuckets.size();

    for (Node *curr = mBuckets[index], *prev = nullptr; curr != nullptr; curr = curr->mNext) {
        if (curr->mData == key) {
            if (prev == nullptr) {
                mBuckets[index] = curr->mNext;
                delete curr;
            }

            else {
                prev->mNext = curr->mNext;
            }
            delete curr;
            --mSize;
            return true;
        }
        prev = curr;
    }
    return false;
}

std::size_t HashSetStr::defaultHashFunc(const std::string &key) {
    std::size_t res = 0;

    for (auto ch : key) {
        res ^= 31 * ch + 97;
    }
    return res;
}

bool HashSetStr::find(const std::string &key) const {
    std::size_t index = defaultHashFunc(key) % mBuckets.size();

    for (Node *p = mBuckets[index]; p != nullptr; p = p->mNext) {
        if (p->mData == key) {
            return true;
        }
    }

    return false;
}

void HashSetStr::rehash() {
    std::vector<Node *> newBuckets(2 * mBuckets.size() + 1);

    for (std::size_t i = 0; i < mBuckets.size(); i++) {
        for (Node *curr = mBuckets[i]; curr != nullptr;) {
            std::size_t index = defaultHashFunc(curr->mData) % newBuckets.size();
            Node *temp = curr->mNext;

            curr->mNext = newBuckets[index];
            newBuckets[index] = curr;

            curr = temp;
        }
    }

    mBuckets.swap(newBuckets);
}