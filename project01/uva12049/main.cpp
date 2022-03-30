#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int test_case, num1, num2, inp;

    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        unordered_multiset<int> set;
        cin >> num1 >> num2;
        int result = 0;

        while (num1--) {
            cin >> inp;
            set.insert(inp);
        }

        while (num2--) {
            cin >> inp;
            auto it = set.find(inp);
            if (it == set.end()) {
                result++;
            } else {
                set.erase(inp);
            }
        }

        cout << result << endl;
    }
}