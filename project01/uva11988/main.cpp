#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    for (string line; getline(cin, line);) {
        list<char> result;
        auto cursor = result.begin();

        for (auto c : line) {
            if (c == '[') {
                cursor = result.begin();
            } else if (c == ']') {
                cursor = result.end();
            } else {
                result.insert(cursor, c);
            }
        }

        cout << string(result.begin(), result.end()) << endl;
    }
}