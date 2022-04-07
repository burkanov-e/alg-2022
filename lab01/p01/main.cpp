#include <iostream>
#include <list>

using namespace std;

struct Node {
    int mData;
    Node *mPrev;
    Node *mNext;
    Node(int data, Node *prev, Node *next)
        : mData(data), mPrev(prev), mNext(next) {
    }
};

void printInDirectOrder(Node *head) {
    for (Node *p = head; p != nullptr; p = p->mNext) {
        cout << p->mData << " ";
    }
    cout << endl;
}

void printInReversedOrder(Node *tail) {
    for (Node *p = tail; p != nullptr; p = p->mPrev) {
        cout << p->mData << " ";
    }
    cout << endl;
}

void clear(Node *&head, Node *&tail) {
    for (Node *p = head; p != nullptr;) {
        Node *t = p;
        p = p->mNext;
        delete t;
    }
    head = tail = nullptr;
}

void pushBack(Node *&head, Node *&tail, int x) {
    if (head == nullptr) {
        head = tail = new Node(x, nullptr, nullptr);
    } else {
        tail->mNext = new Node(x, tail, nullptr);
        tail = tail->mNext;
    }
}

void insertBefore(Node *&head, Node *&curr, int x) {
    if (head == curr) {
        head->mPrev = new Node(x, nullptr, head);
        head = head->mPrev;
    } else {
        Node *t = new Node(x, curr->mPrev, curr);
        curr->mPrev->mNext = t;
        curr->mPrev = t;
    }
}

Node *erase(Node *&head, Node *&tail, Node *curr) {
    if (head == tail && curr == head) {
        delete curr;
        head = tail = nullptr;
        return nullptr;
    }

    if (head == curr) {
        head->mNext->mPrev = nullptr;
        head = head->mNext;
        delete curr;
        return head;
    }

    if (tail == curr) {
        tail->mPrev->mNext = nullptr;
        tail = tail->mPrev;
        delete curr;
        return nullptr;
    }

    curr->mNext->mPrev = curr->mPrev;
    curr->mPrev->mNext = curr->mNext;

    Node *r = curr->mNext;

    delete curr;

    return r;
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int x; cin >> x;) {
        pushBack(head, tail, x);
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    for (Node *p = head; p != nullptr; p = p->mNext) {
        if (p->mData % 2 == 0) {
            insertBefore(head, p, 0);
        }
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    for (Node *p = head; p != nullptr;) {
        if (p->mData % 2 == 0) {
            p = erase(head, tail, p);
        } else {
            p = p->mNext;
        }
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    clear(head, tail);
}
