#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class Solver {
    enum class VertexState {
        Udentified,
        Defined,
        AddedToTree
    };

    int mNumOfVertices;
    // pair <int, int> -> {vertex, weight}
    vector<vector<pair<int, int>>> graph;

   public:
    Solver(int numOfVertrices)
        : mNumOfVertices(numOfVertrices), graph(mNumOfVertices) {
        char u;
        char v;
        char w;

        while (cin >> u >> v >> w) {
            graph[u - 'a'].emplace_back(v - 'a', w);
            graph[v - 'a'].emplace_back(u - 'a', w);
        }
    }

    void run() {
        const int kNoPreds = -1;

        int totalWeight = 0;

        vector<VertexState> states(mNumOfVertices, VertexState::Udentified);
        // numeric_limits<int>::max  --> allocate to infinity
        vector<int> dists(mNumOfVertices, numeric_limits<int>::max());
        vector<int> preds(mNumOfVertices, kNoPreds);

        // pair<int, int> -> (weight, vertex)
        set<pair<int, int>> border;
        border.emplace(0, 0);

        for (int i = 0; i < mNumOfVertices; i++) {
            auto p = *border.begin();
            border.erase(border.begin());
            states[p.second] = VertexState::AddedToTree;

            if (preds[p.second] != kNoPreds) {
                cout << char(preds[p.second] + 'a') << " " << char(p.second + 'a') << " " << dists[p.second];
                totalWeight += dists[p.second];
            }

            for (auto e : graph[p.second]) {
                if (states[e.first] == VertexState::Udentified) {
                    states[e.first] = VertexState::Defined;
                    dists[e.first] = e.second;
                    preds[e.first] = p.second;
                    border.emplace(e.second, e.first);
                }

                else if (states[e.first] == VertexState::Defined && dists[e.first] > e.second) {
                    border.erase({dists[e.first], e.first});
                    dists[e.first] = e.second;
                    preds[e.first] = p.second;
                    border.emplace(dists[e.first], e.first);
                }
            }
        }
        cout << "MST weight: " << totalWeight << "\n";
    }
};

int main() {
    iostream::sync_with_stdio(false);

    int n;
    cin >> n;

    Solver(n).run();
}
