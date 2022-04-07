#include <iostream>
#include <sstream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include "TreeSetInt.hpp"

using namespace std;

TEST_CASE("Default Constructor") {
    TreeSetInt s;

    REQUIRE(s.size() == 0);
}

TEST_CASE("insert") {
    TreeSetInt s;

    s.insert(50);
    s.insert(30);
    s.insert(74);
    s.insert(12);
    s.insert(35);
    s.insert(66);
    s.insert(99);

    REQUIRE(s.size() == 7);

    ostringstream sout;
    s.print(sout);
    REQUIRE(sout.str() == "12 30 35 50 66 74 99");
}

TEST_CASE("erase") {
    TreeSetInt s;

    s.insert(50);
    s.insert(30);
    s.insert(74);
    s.insert(12);
    s.insert(35);
    s.insert(66);
    s.insert(99);

    ostringstream sout;

    SUBCASE("erase leaf") {
        REQUIRE(s.erase(12));
        REQUIRE(s.size() == 6);
        s.print(sout);
        REQUIRE(sout.str() == " 30 35 50 60 74 99");

        s.erase(99);
        REQUIRE(s.size() == 5);
        sout.str("");
        s.print(sout);
        REQUIRE(sout.str() == " 30 35 50 60 74");
    }

    SUBCASE("erase a node with one child") {
        s.insert(80);
        s.insert(88);
        REQUIRE(s.erase(99));
        REQUIRE(s.size() == 8);
        s.print(sout);
        REQUIRE(sout.str() == " 12 30 35 50 60 74 80 88");
    }
}