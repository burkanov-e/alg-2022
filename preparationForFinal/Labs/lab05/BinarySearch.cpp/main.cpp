#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &v, const int &x) {
    int left = 0, right = v.size();

    while (left <= right) {
        int midPoint = left + (right - left) / 2;

        if (v[midPoint] == x) {
            return midPoint;
        } else if (v[midPoint] < x) {
            left = midPoint - 1;
        } else {
            right = midPoint + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    int ans = binarySearch(v, 4);

    cout << ans << endl;
}