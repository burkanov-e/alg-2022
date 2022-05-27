#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

int separation(vector<int> &v, int low, int high) {
    int last = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (v[j] < last) {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[high]);
    return (i + 1);
}

void quickSort(vector<int> &v, int low, int high) {
    if (low < high) {
        int si = separation(v, low, high);

        quickSort(v, low, si - 1);
        quickSort(v, si + 1, high);
    }
}

int main() {
    vector<int> v = {10, 30, 20, 50, 40, 45, 75, 60, 90};

    quickSort(v, 0, v.size() - 1);
    printVector(v);
}