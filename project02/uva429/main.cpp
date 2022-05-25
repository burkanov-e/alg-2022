#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int solve(const string &start, const string &end, const unordered_set<string> &words) {
    unordered_map<string, bool> visited;

    for (const auto &word : words) {
        visited[word] = false;
    }

    unordered_map<string, int> distances;

    queue<string> q;
    q.push(start);
    visited[start] = true;
    distances[start] = 0;
    bool found = false;

    while (!q.empty() && !found) {
        string curr = q.front();
        q.pop();
        int currDist = distances[curr];
        for (int i = 0; i < sz(curr) && !found; i++) {
            char temp = curr[i];

            for (char c = 'a'; c <= 'z' && !found; c++) {
                curr[i] = c;
                if (words.count(curr) != 0 && !visited[curr]) {
                    q.push(curr);
                    visited[curr] = true;
                    distances[curr] = currDist + 1;
                    found = curr == end;
                }
            }
            curr[i] = temp;
        }
    }

    return distances[end];
}

int main() {
    iostream::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        unordered_set<string> words;

        if (test_case != 0) {
            cout << "\n";
        }

        for (string word; cin >> word && word != "*";) {
            words.insert(word);
        }

        string line;
        getline(cin, line);

        while (getline(cin, line) && !line.empty()) {
            istringstream sinp(line);

            string startWord;
            sinp >> startWord;

            string endWord;
            sinp >> endWord;

            cout << startWord << " " << endWord << " " << solve(startWord, endWord, words) << "\n";
        }
    }
}