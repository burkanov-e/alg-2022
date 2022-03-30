#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int a, b;
    while (true) {
        cin >> a >> b;

        if (a == 0 && b == 0) {
            break;
        }

        unordered_set<int> sets;
        int result = 0;

        while (a--) {
            int inp;
            cin >> inp;
            sets.insert(inp);
        }

        while (b--) {
            int inp;
            cin >> inp;
            if (sets.find(inp) != sets.end()) {
                result++;
            }
        }
        cout << result << endl;
    }
}