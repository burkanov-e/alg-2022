#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int wordsCount, test_case;
    cin >> wordsCount >> test_case;
    unordered_map<string, int> mp;

    while (wordsCount--) {
        string word;
        int value;
        cin >> word >> value;
        mp[word] = value;
    }

        while (test_case--) {
        int ans = 0;
        string inp;
        while (cin >> inp && inp != ".") {
            ans += mp[inp];
        }

        cout << ans << endl;
    }
}