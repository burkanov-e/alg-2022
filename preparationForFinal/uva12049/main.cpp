#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    while (test_case--) {
        int inp1, inp2;
        cin >> inp1 >> inp2;

        unordered_multiset<int> set;

        int result = 0;

        while (inp1--) {
            int input;
            cin >> input;
            set.insert(input);
        }

        while (inp2--) {
            int input;
            cin >> input;

            if (set.find(input) == set.end()) {
                result++;
            } else {
                set.erase(input);
            }
        }

        result += set.size();

        cout << result << endl;
    }
}