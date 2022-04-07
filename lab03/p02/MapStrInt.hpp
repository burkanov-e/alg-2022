#pragma once

#include <iostream>
#include <string>
#include <utility>

class MapStrInt {
    struct Node {
        std::pair<const std::string, int> mData;
        Node *mLeft;
        Node *mRight;

        Node(const std::pair<std::string, int> &data, Node *left, Node *right)
            : mData(data), mLeft(left), mRight(right) {
        }
    };

    // recursive
    void print(Node *root) const {
        if (root != nullptr) {
            print(root->mLeft);
            std::cout << root->mData.first << ": " << root->mData.second << std::endl;
            print(root->mRight);
        }
    }

    // recursive
    void clear(Node *root) {
        if (root != nullptr) {
            clear(root->mLeft);
            clear(root->mRight);
            delete root;
            --mSize;
        }
    }

   public:
    Node *mRoot;
    std::size_t mSize;

    MapStrInt()
        : mRoot(nullptr), mSize(0) {}

    ~MapStrInt() {
        clear(mRoot);
    }

    int &operator[](const std::string &k);

    std::size_t size() const {
        return mSize;
    }

    void print() const {
        print(mRoot);
    }

    void clear() {
        clear(mRoot);
    }
};