#pragma once

#include <cstddef>
#include <iterator>
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
    List() noexcept : mAnchor(&mAnchor, &mAnchor), mSize(0) {}

    List(const List &other)
        : List()
    // mAnchor(&mAnchor, &mAnchor), mSize(0)
    {
        // try {
        for (const auto &e : other) {
            pushBack(e);
        }
        // } catch (...) {
        //     clear();
        //     throw;
        // }
    }

    List &operator=(const List &other) {
        List cpy(other);
        swap(cpy);
        return *this;
    }

    List(List &&other) noexcept
        : mAnchor(&mAnchor, &mAnchor), mSize(0) {
        if (!other.empty()) {
            mAnchor = other.mAnchor;
            mSize = other.mSize;
            mAnchor.mPrev->mNext = &mAnchor;
            mAnchor.mNext->mPrev = &mAnchor;
            other.mAnchor.mPrev = other.mAnchor.mNext = &other.mAnchor;
            other.mSize = 0;
        }
    }

    List &operator=(List &&other) noexcept {
        List cpy(std::move(other));
        cpy.swap(*this);
        return *this;
    }

    ~List() {
        clear();
    }

    void clear() {
        for (Link *p = mAnchor.mNext; p != &mAnchor;) {
            Link *t = p->mNext;
            delete static_cast<Node *>(p);
            p = t;
        }

        mAnchor.mPrev = mAnchor.mNext = &mAnchor;
        mSize = 0;
    }

    void swap(List &other) noexcept {
        if (this == &other || (empty() && other.empty())) {
            return;
        }

        if (empty()) {
            mAnchor = other.mAnchor;
            mAnchor.mNext->mPrev = &mAnchor;
            mAnchor.mPrev->mNext = &mAnchor;

            other.mAnchor.mPrev = other.mAnchor.mNext = &other.mAnchor;
        } else if (other.empty()) {
            other.mAnchor = mAnchor;
            other.mAnchor.mNext->mPrev = &other.mAnchor;
            other.mAnchor.mPrev->mNext = &other.mAnchor;

            mAnchor.mPrev = mAnchor.mNext = &mAnchor;
        } else {
            std::swap(mAnchor, other.mAnchor);
            mAnchor.mNext->mPrev = &mAnchor;
            mAnchor.mPrev->mNext = &mAnchor;
            other.mAnchor.mNext->mPrev = &other.mAnchor;
            other.mAnchor.mPrev->mNext = &other.mAnchor;
        }

        std::swap(mSize, other.mSize);
    }

    size_t size() const {
        return mSize;
    }

    bool empty() const {
        return mSize == 0;
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
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;
        using value_type = T;

        Iter() : mPointerToElem(nullptr) {}

        Iter &operator++() {
            mPointerToElem = mPointerToElem->mNext;
            return *this;
        }

        Iter operator++(int) {
            Iter r(*this);
            mPointerToElem = mPointerToElem->mNext;
            return r;
        }

        Iter &operator--() {
            mPointerToElem = mPointerToElem->mPrev;
            return *this;
        }

        Iter operator--(int) {
            Iter r(*this);
            mPointerToElem = mPointerToElem->mPrev;
            return r;
        }

        bool operator==(Iter other) const {
            return mPointerToElem == other.mPointerToElem;
        }

        bool operator!=(Iter other) const {
            return !(*this == other);
        }

        T &operator*() const {
            return static_cast<Node *>(mPointerToElem)->mData;
        }

        T *operator->() const {
            return &static_cast<Node *>(mPointerToElem)->mData;
        }
    };

    class CIter {
        friend class List;
        const Link *mPointerToElem;

       public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using pointer = const T *;
        using reference = const T &;
        using value_type = const T;

        CIter() : mPointerToElem(nullptr) {}

        CIter &operator++() {
            mPointerToElem = mPointerToElem->mNext;
            return *this;
        }

        CIter operator++(int) {
            CIter r(*this);
            mPointerToElem = mPointerToElem->mNext;
            return r;
        }

        CIter &operator--() {
            mPointerToElem = mPointerToElem->mPrev;
            return *this;
        }

        CIter operator--(int) {
            CIter r(*this);
            mPointerToElem = mPointerToElem->mPrev;
            return r;
        }

        bool operator==(CIter other) const {
            return mPointerToElem == other.mPointerToElem;
        }

        bool operator!=(CIter other) const {
            return !(*this == other);
        }

        const T &operator*() const {
            return static_cast<const Node *>(mPointerToElem)->mData;
        }

        const T *operator->() const {
            return &static_cast<const Node *>(mPointerToElem)->mData;
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

    CIter begin() const {
        CIter r;
        r.mPointerToElem = mAnchor.mNext;
        return r;
    }

    CIter end() const {
        CIter r;
        r.mPointerToElem = &mAnchor;
        return r;
    }

    Iter insert(Iter it, const T &x) {
        Link *curr = it.mPointerToElem;

        Node *node = new Node(x, curr->mPrev, curr);
        curr->mPrev->mNext = node;
        curr->mPrev = node;

        ++mSize;
        return --it;
    }

    void pushBack(const T &x) {
        // mAnchor.mPrev = mAnchor.mPrev->mNext = new Node(x, mAnchor.mPrev, &mAnchor);
        // ++mSize;

        insert(end(), x);
    }

    void pushFront(const T &x) {
        insert(begin(), x);
    }
};