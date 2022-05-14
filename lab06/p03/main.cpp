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
    unordered_map<string, int> dists;
    unordered_map<string, string> preds;

    unordered_map<string, vector<string>> graph;

    int numEdges;
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        string u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);

        colors[u] = Color::White;
        colors[v] = Color::White;

        preds[u] == "null";
        preds[v] == "null";
    }

    string source, dest;
    cin >> source >> dest;

    queue<string> redVertices;
    preds[source] = "null";

    colors[source] = Color::Red;
    dists[source] = 0;
    redVertices.push(source);

    while (!redVertices.empty()) {
        string u = redVertices.front();
        redVertices.pop();

        colors[u] = Color::Black;

        for (auto v : graph[u]) {
            if (colors[v] == Color::White) {
                colors[v] = Color::Red;
                preds[v] = u;
                dists[v] = dists[u] + 1;
                redVertices.push(v);
            }
        }
    }

    for (auto p : dists) {
        cout << p.first << ": " << p.second << endl;
    }

    vector<string> path;
    path.push_back(dest);

    while (preds[path.back()] != "null") {
        path.push_back(preds[path.back()]);
    }

    reverse(begin(path), end(path));

    for (auto e : path) {
        cout << " " << e;
    }
    cout << endl;
}