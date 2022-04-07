#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> langCounters;

    for (string lang; cin >> lang;) {
        ++langCounters[lang];
    }

    for (const auto &p : langCounters) {
        cout << p.first << ": " << p.second << endl;
    }
}