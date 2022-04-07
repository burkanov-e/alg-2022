#include "MapStrInt.hpp"

int &MapStrInt::operator[](const std::string &k) {
    Node *prev = nullptr;
    Node *curr = mRoot;
    bool isLeft = false;

    while (curr != nullptr) {
        if (curr->mData.first < k) {
            prev = curr;
            curr = curr->mRight;
            isLeft = false;
        }

        else if (k < curr->mData.first) {
            prev = curr;
            curr = curr->mLeft;
            isLeft = true;
        } else {
            return curr->mData.second;
        }
    }

    Node *t = new Node(std::make_pair(k, 0), nullptr, nullptr);
    ++mSize;

    if (prev == nullptr) {
        mRoot = t;
    }
    if (isLeft) {
        prev->mLeft = t;
    } else {
        prev->mRight = t;
    }

    return t->mData.second;
}