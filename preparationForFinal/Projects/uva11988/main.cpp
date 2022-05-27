#include <bits/stdc++.h>

template <typename C>
int sz(const C& c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    for (string line; getline(cin, line);) {
        list<char> res;
        auto it = res.begin();

        for (auto& c : line) {
            if (c == '[') {
                it = res.begin();
            } else if (c == ']') {
                it = res.end();
            } else {
                res.insert(it, c);
            }
        }

        cout << string(res.begin(), res.end()) << endl;
    }
}