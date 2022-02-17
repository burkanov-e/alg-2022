#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

void printInDirectOrder(const list<int>& first) {
    for (auto e : first) {
        cout << e << " ";
    }
    cout << endl;
}

void printInReversedOrder(const list<int>& first) {
    for (auto it = first.rbegin(); it != first.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    list<int> first;

    for (int x; cin >> x;) {
        first.push_back(x);
    }

    printInDirectOrder(first);
    printInReversedOrder(first);

    for (auto p = first.begin(); p != first.end(); p++) {
        if (*p % 2 == 0) {
            first.insert(p, 0);
        }
    }

    printInDirectOrder(first);
    printInReversedOrder(first);

    for (auto p = first.begin(); p != first.end();) {
        if (*p % 2 == 0) {
            p = first.erase(p);
        } else {
            p++;
        }
    }

    printInDirectOrder(first);
    printInReversedOrder(first);

    reverse(first.begin(), first.end());
}