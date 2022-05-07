#include "sort.hpp"

#include <cstdlib>
#include <map>
#include <utility>
#include <vector>

std::string toStr(const std::vector<int> &v) {
    std::string str = "{";

    for (int i = 0; i < (int)v.size(); ++i) {
        str += std::to_string(v[i]);
        if (i != (int)v.size() - 1) {
            str += ", ";
        }
    }
    str += "}";
    return str;
}

int binarySearch(const std::vector<int> &v, const int &x) {
    int left = 0, right = v.size() - 1;

    while (left <= right) {
        int midPoint = left + (right - left) / 2;

        if (v[midPoint] == x) {
            return midPoint;
        }

        else if (v[midPoint] < x) {
            left = midPoint + 1;
        }

        else {
            right = midPoint - 1;
        }
    }

    return -1;
}

void insertionSort(std::vector<int> &v) {
    int sz = v.size();

    for (int i = 1; i < sz; i++) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}
