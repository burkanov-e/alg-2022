#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;
// Abstract Data Type SET
// collection of unique elements
//  -- insert(k)
//  -- erase(k)
//  -- find(k)

// unordered_set: Its implementation using hash table
// unordered collection of unique elements
// insert(k), erase(k), find(k) -- O(1)

// hashing

int main() {
    unordered_set<string> setOfWords;

    auto hf = setOfWords.hash_function();

    for (string line; getline(cin, line);) {
        cout << "load factor: " << setOfWords.max_load_factor() << endl;
        istringstream simp(line);
        string cmd;
        simp >> cmd;

        if (cmd == "#") {
            for (size_t i = 0; i < setOfWords.bucket_count(); ++i) {
                cout << setw(4) << i << ":";
                for (auto it = setOfWords.begin(i); it != setOfWords.end(i); ++it) {
                    cout << " " << *it;
                }
                cout << endl;
            }
        }

        else if (cmd == "%") {
            for (const auto &e : setOfWords) {
                cout << " " << e;
            }
            cout << endl;
        }

        else if (cmd == "+") {
            string word;
            simp >> word;

            cout << "hash value: " << hf(word) << endl;
            cout << (setOfWords.insert(word).second ? "YES" : "NO") << endl;
            cout << "index: " << hf(word) % setOfWords.bucket_count() << endl;
        }

        else if (cmd == "-") {
            string word;
            simp >> word;

            cout << "hash value: " << hf(word) << endl;
            cout << (setOfWords.erase(word) ? "YES" : "NO") << endl;
            cout << "index: " << hf(word) % setOfWords.bucket_count() << endl;
        }

        else if (cmd == "?") {
            string word;
            simp >> word;

            cout << "hash value: " << hf(word) << endl;
            cout << "index: " << hf(word) % setOfWords.bucket_count() << endl;
            cout << (setOfWords.find(word) != setOfWords.end() ? "YES" : "NO") << endl;
        }
    }
}