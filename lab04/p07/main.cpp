#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// backtracking ()
class Solver {
    int mSize;
    vector<bool> mRows;
    vector<bool> mDiag1;
    vector<bool> mDiag2;
    vector<int> mSolution;
    int mCurrNum;

   public:
    Solver(int size)
        : mSize(size), mRows(size), mDiag1(2 * size - 1), mDiag2(2 * size - 1), mSolution(mSize), mCurrNum(0) {}

    void solve(int col) {
        if (col == mSize) {
            print();
        } else {
            for (int row = 0; row < mSize; ++row) {
                if (canPutQueen(row, col)) {
                    putQueen(row, col);
                    solve(col + 1);
                    takeQueen(row, col);
                }
            }
        }
    }

    void run() {
        solve(0);
    }

    void putQueen(int row, int col) {
        mRows[row] = true;
        mDiag1[row + col] = true;
        mDiag2[mSize - 1 - (row - col)] = true;
        mSolution[col] = row;
    }

    void takeQueen(int row, int col) {
        mRows[row] = false;
        mDiag1[row + col] = false;
        mDiag2[mSize - 1 - (row - col)] = false;
        mSolution[col] = row;
    }

    bool canPutQueen(int row, int col) {
        return !mRows[row] && !mDiag1[row + col] && !mDiag2[mSize - 1 - row + col];
    }

    void print() {
        cout << setw(3) << ++mCurrNum;
        for (auto row : mSolution) {
            cout << " " << row;
        }
        cout << endl;
    }
};

int main() {
    for (int n; cin >> n;) {
        Solver(n).run();
    }
}