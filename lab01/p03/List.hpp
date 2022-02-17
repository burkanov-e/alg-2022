#pragma once

#include <cstddef>
#include <sstream>
#include <string>

template <typename T>

class List {
    struct Link {
        Link *mPrev;
        Link *mNext;

        Link(Link *prev, Link *next) : mPrev(prev), mNext(next) {}
    };

    struct Node : Link {
        // invisible part
        // Link *mPrev;
        // Link *mNext;

        T mData;
        Node(const T &data, Link *prev, Link *next) : Link(prev, next), mData(data) {}
    };

    Link mAnchor;
    std::size_t mSize;

   public:
    List() : mAnchor(&mAnchor, &mAnchor), mSize(0) {}

    ~List() {
        clear();
    }

    void clear() {
        for (Link *p = mAnchor.mNext; p != &mAnchor;) {
            Link *t = p->mNext;
            delete static_cast<Node *>(p);
            p = t;
        }
        mSize = 0;
    }

    size_t size() const {
        return mSize;
    }

    void pushBack(const T &x) {
        mAnchor.mPrev = mAnchor.mPrev->mNext = new Node(x, mAnchor.mPrev, &mAnchor);
        ++mSize;
    }

    std::string toStr() const {
        std::ostringstream sout;

        sout << "{";

        bool isFirst = true;
        for (Link *p = mAnchor.mNext; p != &mAnchor; p = p->mNext) {
            if (!isFirst) {
                sout << ", ";
            }
            sout << static_cast<Node *>(p)->mData;
            isFirst = false;
        }
        sout << "}";
        return sout.str();
    }

    std::string toReverseStr() const {
        std::ostringstream sout;

        sout << "{";

        bool isFirst = true;
        for (Link *p = mAnchor.mPrev; p != &mAnchor; p = p->mPrev) {
            if (!isFirst) {
                sout << ", ";
            }
            sout << static_cast<Node *>(p)->mData;
            isFirst = false;
        }
        sout << "}";
        return sout.str();
    }

    class Iter {
        friend class List;
        Link *mPointerToElem;

       public:
        Iter() : mPointerToElem(nullptr) {}

        Iter &operator++() {
            mPointerToElem = mPointerToElem->mNext;
            return *this;
        }

        bool operator==(Iter other) const {
            return mPointerToElem == other.mPointerToElem;
        }

        bool operator!=(Iter other) const {
            return (*this == other);
        }

        T &operator*() const {
            return static_cast<Node *>(mPointerToElem)->mData;
        }
    };

    Iter begin() {
        Iter r;
        r.mPointerToElem = mAnchor.mNext;
        return r;
    }

    Iter end() {
        Iter r;
        r.mPointerToElem = &mAnchor;
        return r;
    }
};