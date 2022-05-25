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

        unordered_set<int> set;
        int result = 0;

        for (int i = 0; i < a; i++) {
            int input;
            cin >> input;
            set.insert(input);
        }

        for (int i = 0; i < b; i++) {
            int input;
            cin >> input;

            if (set.find(input) != set.end()) {
                result++;
            }
        }

        cout << result << endl;
    }
}