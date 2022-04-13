#include <cstdint>
#include <iostream>

using namespace std;

int64_t fib(int n) {
    return n < 2 ? 1 : fib(n - 1) + fib(n - 2);
}

int64_t fibIter(int n) {
    if (n <= 2) {
        return 1;
    }

    int64_t a = 1;
    int64_t b = 1;

    for (int i = 3; i <= n; ++i) {
        int64_t next = a + b;
        a = b;
        b = next;
    }

    return a;
}
int main() {
    for (int n; cin >> n;) {
        cout << fibIter(n) << endl;
    }
}