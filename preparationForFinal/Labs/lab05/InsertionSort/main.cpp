#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &v) {
    for (int i = 1; i < (int)v.size(); i++) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && j > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void printVector(const vector<int> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

int main() {
    vector<int> v = {10, 30, 20, 50, 40, 45, 75, 60, 90};

    insertionSort(v);
    printVector(v);
}