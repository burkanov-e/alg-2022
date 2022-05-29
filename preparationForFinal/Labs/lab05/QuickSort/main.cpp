#include <iostream>
#include <vector>

using namespace std;

int separation(vector<int> &v, int low, int high) {
    int i = (low - 1);
    int last = v[high];

    for (int j = low; j <= high; j++) {
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
    vector<int> v{1, 20, 30, 43, 32, 45, 11, 33};
    quickSort(v, 0, v.size() - 1);

    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}