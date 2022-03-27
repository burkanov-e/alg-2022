#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;

        unordered_set<string> set1;
        unordered_set<string> set2;

        while (inp1--) {
            string text;
            cin >> text;
            set1.insert(text);
        }

        while (inp2--) {
            string text;
            cin >> text;
            set2.insert(text);
        }

        int c = set1.size() * set2.size();

        cout << "Case " << i + 1 << ": " << c << endl;
    }
}