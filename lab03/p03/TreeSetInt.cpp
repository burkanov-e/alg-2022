#include "TreeSetInt.hpp"

#include <utility>
#include <vector>

using namespace std;

bool TreeSetInt::insert(int k) {
    Node *prev = nullptr;
    Node *curr = mRoot;
    bool isLeft = false;

    while (curr != nullptr) {
        if (curr->mData < k) {
            isLeft = false;
            prev = curr;
            curr = curr->mRight;
        }

        else if (k < curr->mData) {
            isLeft = true;
            prev = curr;
            curr = curr->mLeft;
        } else {
            return false;
        }
    }

    Node *newNode = new Node(k, nullptr, nullptr);
    ++mSize;

    if (mRoot == nullptr) {
        mRoot = newNode;
    } else if (!isLeft) {
        prev->mRight = newNode;
    } else {
        prev->mRight = newNode;
    }

    return true;
}

void TreeSetInt::print(std::ostream &out) const {
    enum class Operation { GoLeft,
                           Print,
                           GoRight,
                           Finish };

    vector<pair<Node *, Operation>> stack;

    stack.emplace_back(mRoot, Operation::GoLeft);
    while (!stack.empty()) {
        if (stack.back().first == nullptr || stack.back().second == Operation::Finish) {
            stack.pop_back();
        } else if (stack.back().second == Operation::GoLeft) {
            stack.back().second = Operation::Print;
            stack.emplace_back(stack.back().first->mLeft, Operation::GoLeft);
        } else if (stack.back().second == Operation::Print) {
            out << " " << stack.back().first->mData;
            stack.back().second = Operation::GoRight;
        } else if (stack.back().second == Operation::GoRight) {
            stack.back().second = Operation::Finish;
            stack.emplace_back(stack.back().first->mRight, Operation::GoLeft);
        }
    }
}

bool TreeSetInt::erase(int k) {
    Node *prev = nullptr;
    Node *curr = mRoot;
    bool isLeft = false;
    while (curr != nullptr) {
        if (curr->mData < k) {
            isLeft = false;
            prev = curr;
            curr = curr->mRight;
        } else if (k < curr->mData) {
            isLeft = true;
            prev = curr;
            curr = curr->mLeft;
        } else {
            break;
        }
    }

    if (curr == nullptr) {
        return false;
    }

    if (curr->mLeft == nullptr && curr->mRight == nullptr) {
        eraseLeaf(prev, curr, isLeft);
    } else if ((curr->mLeft != nullptr) ^ (curr->mRight == nullptr)) {
        eraseNodeWithOneChild(prev, curr, isLeft);
    }

    return true;
}

void TreeSetInt::eraseLeaf(Node *prev, Node *curr, bool isLeft) {
    if (prev == nullptr) {
        mRoot = nullptr;
    } else if (isLeft) {
        prev->mLeft = nullptr;
    } else {
        prev->mRight = nullptr;
    }

    delete curr;
    --mSize;
}

void TreeSetInt::eraseNodeWithOneChild(Node *prev, Node *curr, bool isLeft) {
    if (curr == mRoot) {
        mRoot = mRoot->mLeft != nullptr ? curr->mLeft : curr->mRight;
    }

    if (isLeft) {
        prev->mLeft = curr->mLeft != nullptr ? curr->mLeft : curr->mRight;
    } else {
        prev->mRight = curr->mLeft != nullptr ? curr->mLeft : curr->mRight;
    }

    delete curr;
    --mSize;
}