#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void dfs(int r, int c, vector<vector<char>> &field) {
    static vector<int> dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    static vector<int> dc = {0, 1, 1, 1, 0, -1, -1, -1};

    field[r][c] = 'V';

    for (int i = 0; i < sz(dr); i++) {
        int tr = r + dr[i];
        int tc = c + dc[i];

        if (field[tr][tc] == '@') {
            dfs(tr, tc, field);
        }
    }
}

int main() {
    iostream::sync_with_stdio(false);

    for (int rows, cols; cin >> rows >> cols && (rows + cols > 0);) {
        vector<vector<char>> field(rows + 2, vector<char>(cols + 2, '*'));

        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                cin >> field[r][c];
            }
        }

        int res = 0;
        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                if (field[r][c] == '@') {
                    res++;
                    dfs(r, c, field);
                }
            }
        }

        cout << res << "\n";
    }
}