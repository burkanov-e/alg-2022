#include <iostream>

using namespace std;

void readAndPrintRecursive() {
    int x;
    if (cin >> x) {
        readAndPrintRecursive();
        cout << " " << x;
    }
}
int main() {
    readAndPrintRecursive();
    cout << endl;
}