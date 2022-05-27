#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    for (int test = 0; test < test_case; test++) {
        int a, b;
        cin >> a >> b;

        vector<string> input1;
        vector<string> input2;
        unordered_set<string> result;

        while (a--) {
            string line;
            cin >> line;
            input1.push_back(line);
        }

        while (b--) {
            string line;
            cin >> line;
            input2.push_back(line);
        }

        string temp;

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                temp = input1[i] + input2[j];
                result.insert(temp);
            }
        }

        cout << "Case " << test + 1 << ": " << result.size() << endl;
    }
}