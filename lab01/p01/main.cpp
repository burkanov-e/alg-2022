#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> v(1024);
    v.push_back(42);
    v.erase(v.begin());
    //
}
