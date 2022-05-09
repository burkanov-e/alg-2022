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

// BINARY SEARCH
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

// INSERTION SORT
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

// MERGE SORT
void merge(std::vector<int> &v, std::vector<int> &left, std::vector<int> &right) {
    int numLeft = left.size();
    int numRight = right.size();

    int i = 0, l = 0, r = 0;  // l=left and r=right index

    while (l < numLeft && r < numRight) {
        if (left[l] < right[r]) {
            v[i] = left[l];
            l++;
        } else {
            v[i] = right[r];
            r++;
        }
        i++;
    }

    while (l < numLeft) {
        v[i] = left[l];
        l++, i++;
    }

    while (r < numRight) {
        v[i] = right[r];
        r++, i++;
    }
}

void mergeSort(std::vector<int> &v) {
    if (v.size() <= 1) {
        return;
    }

    int mid = v.size() / 2;
    std::vector<int> left;
    std::vector<int> right;

    for (int l = 0; l < mid; l++) {
        left.push_back(v[l]);
    }

    for (size_t r = 0; r < v.size() - mid; r++) {
        left.push_back(v[r + mid]);
    }

    mergeSort(left);
    mergeSort(right);
    merge(v, left, right);
}
