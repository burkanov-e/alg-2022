#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "../doctest/doctest.h"
#include "sort.hpp"

using namespace std;

TEST_CASE("Binary Search") {
    vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80, 85, 90, 95, 99};
    ostringstream sout;

    int res = binarySearch(v, 80);
    REQUIRE(res == 7);

    int res1 = binarySearch(v, 99);
    REQUIRE(res1 == 11);

    int res2 = binarySearch(v, 10);
    REQUIRE(res2 == 0);
}

TEST_CASE("Inseriton Sort") {
    vector<int> v = {10, 30, 20, 50, 40, 45, 75, 60, 90};

    insertionSort(v);
    REQUIRE(toStr(v) == "{10, 20, 30, 40, 45, 50, 60, 75, 90}");
}

TEST_CASE("Merge Sort") {
    vector<int> v = {10, 30, 20, 50, 40, 45, 75, 60, 90};

    mergeSort(v, 0, v.size() - 1);
    REQUIRE(toStr(v) == "{10, 20, 30, 40, 45, 50, 60, 75, 90}");
}