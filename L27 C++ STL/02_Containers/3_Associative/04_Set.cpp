#include <iostream>
#include <set>
using namespace std;

int main() {
    // Initialize an empty set
    // Built on a Red-Black Tree. All operations are O(log N).
    set<int> s;

    // 1. insert & emplace
    s.insert(30);
    s.insert(10);
    s.emplace(20);
    
    // Attempting to insert a duplicate
    s.insert(10); 

    // 2. Proving the "Sorted and Unique" behavior
    cout << "--- Set Contents ---" << endl;
    for (int val : s) {
        // Automatically prints: 10 20 30 (The duplicate 10 was silently ignored)
        cout << val << " "; 
    }
    cout << "\n" << endl;

    // 3. count (Returns 1 if present, 0 if not)
    cout << "Does 20 exist? " << s.count(20) << endl;

    // 4. find (Returns an iterator pointing to the memory address)
    if (s.find(30) != s.end()) {
        cout << "30 found in memory!" << endl;
    }

    // 5. size, empty, erase
    cout << "\nSize before erase: " << s.size() << endl;
    
    s.erase(10); // Physically removes the node from the tree
    
    cout << "Size after erase: " << s.size() << endl;
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}