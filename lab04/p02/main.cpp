#include <iostream>
#include <stdexcept>

using namespace std;

int64_t gcdAux(int64_t a, int64_t b) {
    return a == 0 || b == 0 ? a + b : gcdAux(b, a % b);
}

int64_t gcd(int64_t a, int64_t b) {
    if (a == 0 && b == 0) {
        throw runtime_error("gcd(0, 0) is not defined");
    }

    return gcdAux(a, b);
}

int main() {
    for (int64_t a, b; cin >> a >> b;) {
        try {
            cout << gcd(a, b) << endl;
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    }
}