#include "sort.hpp"

#include <cstdlib>
#include <iostream>
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

    // 3 1 12 8

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
// void merge(std::vector<int> &v, std::vector<int> &left, std::vector<int> &right) {
//     int numLeft = left.size();
//     int numRight = right.size();

//     int i = 0, l = 0, r = 0;  // l=left and r=right index

//     while (l < numLeft && r < numRight) {
//         if (left[l] < right[r]) {
//             v[i] = left[l];
//             l++;
//         } else {
//             v[i] = right[r];
//             r++;
//         }
//         i++;
//     }

//     while (l < numLeft) {
//         v[i] = left[l];
//         l++;
//         i++;
//     }

//     while (r < numRight) {
//         v[i] = right[r];
//         r++;
//         i++;
//     }
// }

// void mergeSort(std::vector<int> &v) {
//     if (v.size() <= 1) {
//         return;
//     }

//     int mid = v.size() / 2;
//     std::vector<int> left;
//     std::vector<int> right;

//     for (int l = 0; l < mid; l++) {
//         left.push_back(v[l]);
//     }

//     for (size_t r = 0; r < v.size() - mid; r++) {
//         left.push_back(v[r + mid]);
//     }

//     mergeSort(left);
//     mergeSort(right);
//     merge(v, left, right);
// }

// void merge(std::vector<int> &v, const int &left, const int &mid, const int &right) {
//     // First subarray is v[begin   -   mid]
//     int const subarray1 = mid - left + 1;

//     // Second subarray is v[mid + 1  -  end]
//     int const subarray2 = right - mid;

//     // Create two temp vector

//     std::vector<int> leftVector(subarray1);
//     //std::vector<int> leftVector = new std::vector<int>(subarray1);

// }

void merge(std::vector<int> &v, int const &left, int const &mid, int const &right) {
    // First subarray is arr[begin  -  mid]
    int const subArray1 = mid - left + 1;

    // Second subarray is arr[mid+1  -  end]
    int const subArray2 = right - mid;

    // Create temp vectors
    std::vector<int> leftVector(subArray1);
    std::vector<int> rightVector(subArray2);

    // Copy data to temp leftVector and rightaVector

    for (int i = 0; i < subArray1; i++) {
        leftVector[i] = v[left + i];
    }

    for (int i = 0; i < subArray2; i++) {
        rightVector[i] = v[mid + 1 + i];
    }

    int indexOfSubArray1 = 0;  // Initial index of first sub-array

    int indexOfSubArray2 = 0;  // Initial index of second sub-array

    int indexOfMergedVector = left;  // Initial index of merged array

    // Merge the temp arrays back into array[left..right]

    while (indexOfSubArray1 < subArray1 && indexOfSubArray2 < subArray2) {
        if (leftVector[indexOfSubArray1] <= rightVector[indexOfSubArray2]) {
            v[indexOfMergedVector] = leftVector[indexOfSubArray1];
            indexOfSubArray1++;
        }

        else {
            v[indexOfMergedVector] = rightVector[indexOfSubArray2];
            indexOfSubArray2++;
        }

        indexOfMergedVector++;
    }

    // Copy the remaining elements of rightVector

    while (indexOfSubArray1 < subArray1) {
        v[indexOfMergedVector] = leftVector[indexOfSubArray1];

        indexOfSubArray1++;
        indexOfMergedVector++;
    }

    // Copy the remaining elements of rightVector
    while (indexOfSubArray2 < subArray2) {
        v[indexOfMergedVector] = rightVector[indexOfSubArray2];
        indexOfSubArray2++;
        indexOfMergedVector++;
    }
}

void mergeSort(std::vector<int> &v, int const &beg, int const &end) {
    if (beg >= end) {
        return;  // Returns recursivly
    }

    int mid = beg + (end - beg) / 2;

    mergeSort(v, beg, mid);
    mergeSort(v, mid + 1, end);
    merge(v, beg, mid, end);
}

// QUICK SORT

int separation(std::vector<int> &v, int low, int high) {
    int last = v[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        if (v[j] < last) {
            i++;
            std::swap(v[i], v[j]);
        }
    }

    std::swap(v[i + 1], v[high]);
    return (i + 1);
}

void quickSort(std::vector<int> &v, int low, int high) {
    if (low < high) {
        int si = separation(v, low, high);

        quickSort(v, low, si - 1);
        quickSort(v, si + 1, high);
    }
}
