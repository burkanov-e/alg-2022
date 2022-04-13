#include <iostream>

using namespace std;

void readAndPrintInReverseOrder() {
    int x;
    if (cin >> x) {
        readAndPrintInReverseOrder();
        cout << " " << x;
    }
}

int main() {
    readAndPrintInReverseOrder();
    cout << endl;
}