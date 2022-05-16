#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class Solver {
    const int kNoPred = -1;

    enum class Color {
        White,
        Red,
        Black
    };

    int mSize;
    vector<string> mMaze;
    int mStart;
    int mDest;

    vector<int> mDistances;
    vector<int> mPreds;
    vector<Color> mColors;

    bool inMaze(int r, int c) {
        return 0 <= r && r < mSize && 0 <= c && c < mSize;
    }

   public:
    Solver(int size)
        : mSize(size), mMaze(mSize), mStart(0), mDest(0), mDistances(mSize * mSize), mPreds(mSize * mSize, kNoPred), mColors(mSize * mSize, Color::White) {
        for (int r = 0; r < mSize; r++) {
            cin >> mMaze[r];
            size_t cStart = mMaze[r].find('S');

            if (cStart != string::npos) {
                mStart = r * mSize + int(cStart);
            }

            size_t cDest = mMaze[r].find('D');

            if (cDest != string::npos) {
                mDest = r * mSize + int(cDest);
            }
        }
    }

    void run() {
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        queue<int> q;
        q.push(mStart);
        mColors[mStart] = Color::Red;
        mDistances[mStart] = 0;

        bool found = false;

        while (!q.empty() && !found) {
            int cur = q.front();
            q.pop();
            mColors[cur] = Color::Black;

            int r = cur / mSize;
            int c = cur % mSize;

            for (int i = 0; i < sz(dr) && !found; i++) {
                int tr = r + dr[i];
                int tc = c + dc[i];
                int t = tr * mSize + tc;

                if (inMaze(tr, tc) && mMaze[tr][tc] != '#' && mColors[t] == Color::White) {
                    q.push(t);
                    mColors[t] = Color::Red;
                    mPreds[t] = cur;
                    mDistances[t] = mDistances[cur] + 1;
                    found = t == mDest;
                }
            }
        }
    }

    void printResult() {
        if (mPreds[mDest] == kNoPred) {
            cout << "Unreachable\n";
        } else {
            cout << mDistances[mDest] << "\n";
            int cur = mDest;

            while (cur != mStart) {
                mMaze[cur / mSize][cur % mSize] = '*';
                cur = mPreds[cur];
            }

            for (const auto &e : mMaze) {
                cout << e << "\n";
            }
        }
    }
};

int main() {
    iostream::sync_with_stdio(false);

    int n;
    cin >> n;

    Solver solver(n);
    solver.run();
    solver.printResult();
}
