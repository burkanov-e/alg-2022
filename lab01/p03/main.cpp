#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>

#include "../../doctest/doctest.h"
#include "List.hpp"

using namespace std;

TEST_CASE("List: default constructor") {
    List<int> lst;

    REQUIRE(lst.size() == 0);
}

TEST_CASE("List: pushBack") {
    List<int> lst;

    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    lst.pushBack(4);
    lst.pushBack(5);

    REQUIRE(lst.size() == 5);
    REQUIRE(lst.toStr() == "{1, 2, 3, 4, 5}");
    REQUIRE(lst.toReverseStr() == "{5, 4, 3, 2, 1}");

    List<string> lst2;

    lst2.pushBack("Hello");
    lst2.pushBack("Linked");
    lst2.pushBack("List");

    REQUIRE(lst2.size() == 3);
    REQUIRE(lst2.toStr() == "{Hello, Linked, List}");
}

TEST_CASE("List: Iter") {
    SUBCASE("List: Iter default constructor") {
        List<int>::Iter it;
    }

    SUBCASE("List: ++") {
        List<int> lst;
        lst.pushBack(1);
        lst.pushBack(2);
        lst.pushBack(3);
        lst.pushBack(4);
        lst.pushBack(5);

        int value = 0;

        for (auto it = lst.begin(); it != lst.end(); ++it) {
            ++value;
            REQUIRE(*it == value);
        }

        auto it = lst.begin();
        REQUIRE(*(++it) == 2);
    }
}