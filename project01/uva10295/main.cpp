#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    unordered_map<string, int> mp;

    int countWords, test_case;
    cin >> countWords >> test_case;

    while (countWords--) {
        string word;
        int value;
        cin >> word >> value;
        mp[word] = value;
    }

    while (test_case--) {
        string txt;
        int ans = 0;
        while (cin >> txt, txt != ".") {
            ans += mp[txt];
        }

        cout << ans << endl;
    }
}