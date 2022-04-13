#include <iostream>

using namespace std;

void solve(int nDiscs, int source, int temp, int dest) {
    if (nDiscs > 0) {
        solve(nDiscs - 1, source, dest, temp);
        cout << source << " -> " << dest << endl;
        solve(nDiscs - 1, temp, source, dest);
    }
}

int main() {
    for (int n; cin >> n;) {
        solve(n, 1, 2, 3);
    }
}