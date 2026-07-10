#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Initialize an empty map where the Key is a string, and Value is an int
    map<string, int> m;

    // 1. Insertion & Overwriting (m[key] = value)
    m["tv"] = 50;
    m["laptop"] = 100;
    m["headphones"] = 50;
    
    // Overwriting the existing "tv" key
    m["tv"] = 100; 

    // 2. insert & emplace (Alternative insertion methods)
    m.insert({"camera", 200});
    m.emplace("watch", 150);

    // 3. Proving the "sort (ascending)" behavior
    // They print alphabetically by Key, ignoring insertion order.
    cout << "--- Map Inventory ---" << endl;
    for (auto it : m) {
        cout << it.first << " : " << it.second << endl; // .first is Key, .second is Value
    }

    // 4. count (Checking existence: returns 1 if present, 0 if not)
    cout << "\nDoes 'laptop' exist? " << m.count("laptop") << endl;

    // 5. find (Returns an iterator pointing to the exact memory location of the key)
    if (m.find("tv") != m.end()) {
        cout << "'tv' found in memory!" << endl;
    }

    // 6. size, empty, erase
    cout << "Size before erase: " << m.size() << endl;
    
    m.erase("headphones"); // Physically deletes the key-value pair
    
    cout << "Size after erase: " << m.size() << endl;
    cout << "Is empty? " << (m.empty() ? "Yes" : "No") << endl;

    return 0;
}