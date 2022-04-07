#pragma once

#include <cctype>
#include <iostream>

class TreeSetInt {
    struct Node {
        int mData;
        Node *mLeft;
        Node *mRight;
        Node(int data, Node *left, Node *right) : mData(data), mLeft(left), mRight(right) {}
    };

    Node *mRoot;
    std::size_t mSize;

    void print(Node *root, std::ostream &out) const {
        if (root != nullptr) {
            print(root->mLeft, out);
            out << " " << root->mLeft;
            print(root->mRight, out);
        }
    }

    void clear(Node *root) {
        if (root != nullptr) {
            clear(root->mLeft);
            clear(root->mRight);
            delete root;
            --mSize;
        }
    }

    void eraseLeaf(Node *prev, Node *curr, bool isLeft);
    void eraseNodeWithOneChild(Node *prev, Node *curr, bool isLeft);

   public:
    TreeSetInt() : mRoot(nullptr), mSize(0) {
    }

    ~TreeSetInt() {
        clear();
    }

    std::size_t size() const {
        return mSize;
    }

    void print(std::ostream &out) const;

    void clear() {
        // use non-recursive implementation
        clear(mRoot);
    }

    bool insert(int k);

    bool erase(int k);
};