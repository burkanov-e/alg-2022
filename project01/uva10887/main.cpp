#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int test_case;
    cin >> test_case;
    string text;

    for (int test = 0; test < test_case; test++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;

        vector<string> v1;
        vector<string> v2;

        unordered_set<string> set;

        getline(cin, text);

        for (int i = 0; i < inp1; i++) {
            getline(cin, text);
            v1.push_back(text);
        }

        for (int i = 0; i < inp2; i++) {
            getline(cin, text);
            v2.push_back(text);
        }

        string temp;

        for (int i = 0; i < inp1; i++) {
            for (int j = 0; j < inp2; j++) {
                temp = v1[i] + v2[j];
                set.insert(temp);
            }
        }

        cout << "Case " << test + 1 << ": " << set.size() << endl;
    }
}