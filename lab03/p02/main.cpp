#include <iostream>

#include "MapStrInt.hpp"

using namespace std;

int main() {
    MapStrInt langCounters;

    for (string lang; cin >> lang;) {
        ++langCounters[lang];
    }

    langCounters.print();
}