#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    while (true) {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) {
            break;
        }

        unordered_set<int> res;
        int result = 0;

        while (a--) {
            int inp;
            cin >> inp;
            res.insert(inp);
        }

        while (b--) {
            int inp;
            cin >> inp;

            if (res.find(inp) != res.end()) {
                result++;
            }
        }

        cout << result << endl;
    }
}