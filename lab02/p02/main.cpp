#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>

#include "../../doctest/doctest.h"
#include "HashSetStr.hpp"

using namespace std;

TEST_CASE("Default constructor") {
    HashSetStr set;
    REQUIRE(set.size() == 0);
}

TEST_CASE("insert") {
    HashSetStr set;

    REQUIRE(set.insert("C++"));
    REQUIRE_FALSE(set.insert("C++"));
    REQUIRE(set.size() == 1);

    REQUIRE(set.insert("C"));
    REQUIRE_FALSE(set.insert("C"));
    REQUIRE(set.size() == 2);

    REQUIRE(set.insert("ASM"));
    REQUIRE_FALSE(set.insert("ASM"));
    REQUIRE(set.size() == 3);

    REQUIRE(set.insert("Algol"));
    REQUIRE_FALSE(set.insert("Algol"));
    REQUIRE(set.size() == 4);

    REQUIRE(set.insert("Fortran"));
    REQUIRE_FALSE(set.insert("Fortran"));
    REQUIRE(set.size() == 5);

    set.print();
}

TEST_CASE("find") {
    HashSetStr set;

    REQUIRE(set.insert("C++"));
    REQUIRE(set.insert("C"));
    REQUIRE(set.insert("ASM"));
    REQUIRE(set.insert("Algol"));
    REQUIRE(set.insert("Fortran"));

    REQUIRE(set.find("C++"));
    REQUIRE(set.find("ASM"));
    REQUIRE(set.find("Algol"));
    REQUIRE_FALSE(set.find("Kotlin"));
    set.print();
}

TEST_CASE("erase") {
    HashSetStr set;

    REQUIRE(set.insert("C++"));
    REQUIRE(set.insert("C"));
    REQUIRE(set.insert("ASM"));
    REQUIRE(set.insert("Algol"));
    REQUIRE(set.insert("Fortran"));

    REQUIRE(set.erase("C++"));
    REQUIRE(set.size() == 4);

    REQUIRE(set.erase("Fortran"));
    REQUIRE(set.size() == 3);

    REQUIRE(set.erase("ASM"));
    REQUIRE(set.size() == 2);

    set.print();
}

TEST_CASE("erase") {
    HashSetStr set;

    REQUIRE(set.insert("C++"));
    REQUIRE(set.insert("C"));
    REQUIRE(set.insert("ASM"));

    set.print();

    REQUIRE(set.insert("Algol"));
}