#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

enum class Color {
    White,
    Red,
    Black
};

using AdLists = unordered_map<string, vector<string>>;
using ColorStates = unordered_map<string, Color>;

void dfs(const string &u, AdLists &adLists, ColorStates &colors, list<string> &res) {
    colors[u] = Color::Red;

    // way1: to iterate through adLists[u]  ->   const auto &adLists = adLists.find(u)->second;
    // way2: to remove CONST from adLists in dfs parameter

    for (const auto &v : adLists[u]) {
        if (colors[v] == Color::Red) {
            throw runtime_error("loop");
        }

        if (colors[v] == Color::White) {
            dfs(v, adLists, colors, res);
        }
    }

    colors[u] = Color::Black;

    res.push_front(u);
}

int main() try {
    iostream::sync_with_stdio(false);

    ColorStates colors;
    AdLists adLists;

    for (string item; cin >> item && item != "---";) {
        colors[item] = Color::White;
        adLists[item] = vector<string>();
    }

    // u - origin     v - destination
    for (string u, v; cin >> u >> v;) {
        adLists[u].push_back(v);
    }

    list<string> res;

    for (const auto &p : colors) {
        if (p.second == Color::White) {
            dfs(p.first, adLists, colors, res);
        }
    }

    for (const auto &e : res) {
        cout << " " << e;
    }
    cout << "\n";
} catch (const runtime_error &e) {
    cerr << e.what() << endl;
}