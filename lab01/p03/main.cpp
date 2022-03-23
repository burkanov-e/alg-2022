#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "List.hpp"
#include <algorithm>
#include <string>


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

// TEST_CASE("List: Iter") {
//     SUBCASE("List: Iter default constructor") {
//         List<int>::Iter it;
//     }

//     SUBCASE("++") {
//         List<int> lst;
//         lst.pushBack(1);
//         lst.pushBack(2);
//         lst.pushBack(3);
//         lst.pushBack(4);
//         lst.pushBack(5);

//         int value = 0;

//         for (auto it = lst.begin(); it != lst.end(); ++it) {
//             ++value;
//             REQUIRE(*it == value);
//         }

//         auto it = lst.begin();
//         REQUIRE(*(++it) == 2);

//         REQUIRE(*(it++) == 2);
//     }

//     SUBCASE("--") {
//         List<int> lst;
//         lst.pushBack(1);
//         lst.pushBack(2);
//         lst.pushBack(3);
//         lst.pushBack(4);
//         lst.pushBack(5);

//         int value = 5;

//                 for (auto it = lst.end(); it != lst.begin();) {
//             REQUIRE(*(--it) == value--);
//         }

//         auto it = lst.begin();
//         ++it;
//         ++it;

//         REQUIRE(*(--it) == 2);

//         REQUIRE(*(it--) == 2);
//         REQUIRE(*it == 1);
//     }

//     SUBCASE("std:reverse") {
//         List<int> lst;
//         lst.pushBack(1);
//         lst.pushBack(2);
//         lst.pushBack(3);
//         lst.pushBack(4);
//         lst.pushBack(5);

//         reverse(lst.begin(), lst.end());

//         REQUIRE(lst.toStr() = "{5, 4, 3, 2, 1}");
//     }

//     SUBCASE("->") {
//         List<string> lst;
//         lst.pushBack("Hello");

//         auto it = lst.begin();
//         REQUIRE((*it).size() == 5);
//         REQUIRE(it->size() == 5);
//     }
// }

TEST_CASE("List: insert, pushBack, pushFront") {
    List<int> lst;

    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);

    SUBCASE("pushFront, pushBack") {
        REQUIRE(lst.toStr() == "{1, 2, 3}");
        REQUIRE(lst.toReverseStr() == "{3, 2, 1}");

        lst.pushFront(-1);
        lst.pushFront(-2);
        lst.pushFront(-3);

        REQUIRE(lst.toStr() == "{-3, -2, -1, 1, 2, 3}");
        REQUIRE(lst.toReverseStr() == "{3, 2, 1, -1, -2, -3}");
    }

    SUBCASE("insert") {
        auto it = ++lst.begin();

        REQUIRE(lst.size() == 3);

        lst.insert(it, 9);

        REQUIRE(lst.size() == 4);
        REQUIRE(lst.toStr() == "{1, 9, 2, 3}");
        REQUIRE(lst.toReverseStr() == "{3, 2, 9, 1}");

        auto it2 = lst.insert(lst.begin(), 0);

        REQUIRE(lst.size() == 5);
        REQUIRE(*it2 == *(lst.begin()));
    }
}

struct ThrowableConstructorType {
    ThrowableConstructorType() {
        if (sCurCounter + 1 == sMaxCounter) {
            throw runtime_error("GThrowableConstructorType: too many objects " + to_string(sCurCounter));
        }
        ++sCurCounter;
    }

    ThrowableConstructorType(const ThrowableConstructorType &) {
        if (sCurCounter + 1 == sMaxCounter) {
            throw runtime_error("GThrowableConstructorType: too many objects " + to_string(sCurCounter));
        }
        ++sCurCounter;
    }

    ~ThrowableConstructorType() {
        --sCurCounter;
    }

    static int sCurCounter;
    static int sMaxCounter;
};

int ThrowableConstructorType::sCurCounter;
int ThrowableConstructorType::sMaxCounter;

TEST_CASE("List: copy constructor") {
    SUBCASE("List<int>") {
        List<int> lst;
        lst.pushBack(1);
        lst.pushBack(2);
        lst.pushBack(3);

        auto lst2 = lst;
        REQUIRE(lst2.toStr() == "{1, 2, 3}");
        REQUIRE(lst2.toReverseStr() == "{3, 2, 1}");

        lst.pushBack(4);
        REQUIRE(lst.toStr() == "{1, 2, 3, 4}");
        REQUIRE(lst.toReverseStr() == "{4, 3, 2, 1}");

        REQUIRE(lst2.toStr() == "{1, 2, 3}");
        REQUIRE(lst2.toReverseStr() == "{3, 2, 1}");
    }

    SUBCASE("List<ThrowableConstructorType>") {
        ThrowableConstructorType::sCurCounter = 0;
        ThrowableConstructorType::sMaxCounter = 8;

        List<ThrowableConstructorType> lst;
        ThrowableConstructorType x;

        lst.pushBack(x);
        lst.pushBack(x);
        lst.pushBack(x);
        lst.pushBack(x);
        lst.pushBack(x);

        try {
            auto lst2 = lst;
        } catch (const std::exception &e) {
            cerr << e.what() << '\n';
        }

        REQUIRE(ThrowableConstructorType::sCurCounter == 6);
    }
}
