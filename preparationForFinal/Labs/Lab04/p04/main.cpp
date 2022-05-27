#include <iostream>

using namespace std;

void hanoi(int numOfDiscs, int source, int temp, int dest) {
    if (numOfDiscs > 0) {
        hanoi(numOfDiscs - 1, source, dest, temp);
        cout << source << " -> " << dest << endl;
        hanoi(numOfDiscs - 1, temp, source, dest);
    }
}

int main() {
    for (int x; cin >> x;) {
        hanoi(x, 1, 2, 3);
    }
}