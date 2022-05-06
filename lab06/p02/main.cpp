#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

enum class Color {
    White,
    Red,
    Black
};

int main() {
    iostream::sync_with_stdio(false);

    unordered_map<string, Color> colors;
    unordered_map<string, vector<string>> adLists;

    for (string item; cin >> item;) {
        colors[item] = Color::White;
        adLists[item] = vector<string>();
    }

    for (string u, v; cin >> u >> v;) {
        adLists[u].push_back(v);
    }

    list<string> res;

    for (const auto &p : colors) {
        if (p.second == Color::White) {
        }
    }
}