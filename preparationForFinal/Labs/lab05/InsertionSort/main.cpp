#include <iostream>
#include <vector>

using namespace std;

int insertionSort(vector<int> &v) {
    for (int i = 1; i < (int)v.size(); i++) {
        int last = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > last) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = last;
    }

    return -1;
}

int main() {
    vector<int> v{1, 20, 30, 43, 32, 45, 11, 33};

    insertionSort(v);

    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}