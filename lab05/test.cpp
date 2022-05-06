#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

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