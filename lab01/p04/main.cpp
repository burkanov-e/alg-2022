#include <chrono>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

void count(int n) {
    vector<int> v;
    list<int> lst;

    cout << "n: " << n << endl;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        v.insert(v.begin(), rand());
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by vector: " << duration.count() << " microseconds" << endl;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        lst.insert(lst.begin(), rand());
    }

    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    cout << "Time taken by list: " << duration1.count() << " microseconds" << endl;
}

int main() {
    count(50000);
    count(100000);
    count(150000);
}