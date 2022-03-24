#pragma once

#include <string>
#include <vector>
class HashSetStr {
    struct Node {
        std::string mData;
        Node *mNext;

        Node(const std::string &data, Node *next) : mData(data), mNext(next) {}
    };

    std::vector<Node *> mBuckets;
    std::size_t mSize;

    static std::size_t defaultHashFunc(const std::string &key);

    void rehash();

   public:
    HashSetStr() : mBuckets(3, nullptr), mSize(0) {}

    ~HashSetStr();

    std::size_t size() const {
        return mSize;
    }

    void print() const;
    bool insert(const std::string &key);
    bool find(const std::string &key) const;
    bool erase(const std::string &key);
};