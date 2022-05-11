#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

enum class Color {
    White,
    Red,
    Black
};

void dfs(int u, const vector<vector<int>> &adLists, vector<Color> &colors, vector<int> &components) {
    colors[u] = Color::Red;
    components.push_back(u);
    for (auto v : adLists[u]) {
        if (colors[v] == Color::White) {
            dfs(v, adLists, colors, components);
        }
    }
    colors[u] = Color::Black;
}

int main() {
    iostream::sync_with_stdio(false);

    int numVertices;
    cin >> numVertices;

    vector<vector<int>> adLists(numVertices);
    for (int r = 0; r < numVertices; r++) {
        for (int c = 0; c < numVertices; c++) {
            char ch;
            cin >> ch;

            if (ch == '1') {
                adLists[r].push_back(c);
            }
        }
    }

    // adjecency lists
    // int row = 0;

    // for (const auto &list : adLists) {
    //     cout << row++ << ": ";
    //     for (auto v : list) {
    //         cout << " " << v;
    //     }

    //     cout << "\n";
    // }

    vector<Color> colors(numVertices, Color::White);

    int nComponets = 0;
    for (int i = 0; i < numVertices; i++) {
        if (colors[i] == Color::White) {
            vector<int> curComponents;
            dfs(i, adLists, colors, curComponents);
            cout << ++nComponets << ": ";

            for (auto u : curComponents) {
                cout << " " << u;
            }
            cout << "\n";
        }
    }
}