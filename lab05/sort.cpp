#include "sort.hpp"

#include <bits/stdc++.h>

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
