#include <iostream>

using namespace std;

int factorial(int n) {
    return n == 0 ? 1 : n * factorial(n - 1);
}

int main() {
    for (int x; cin >> x;) {
        cout << factorial(x) << endl;
    }
}