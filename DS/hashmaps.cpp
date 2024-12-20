#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> m;

    // Insertion
    pair<string, int> p = make_pair("noi", 2);
    m.insert(p);

    pair<string, int> p2("is", 4);
    m["hello"] = 1;
    m["benjour"] = 3;

    // Accessing existing keys
    cout << m["hello"] << endl;
    cout << m.at("benjour") << endl;

    // Checking if key exists before using at()
    if (m.find("hhh") != m.end()) {
        cout << m.at("hhh") << endl;
    }
    else {
        cout << "Key 'hhh' not found in map (using at())." << endl;
    }

    // Using operator[] for safe access
    cout << m["hhh"] << endl; // This will add a new key with value 0

    cout << m.size() << endl;

    //check presence
    cout << m.count("hello") << endl;

    //erase
    m.erase("hello");

    cout << m.size() << endl;

    unordered_map<string, int> ::iterator it = m.begin();

    while (it != m.end()) {
        cout << it->first << it->second << endl;
        it++;
    }


    return 0;
}
