#include <iostream>
#include <set>
#include <unordered_set> // Required for unordered version
using namespace std;

int main() {
    // ---------------------------------------------------------
    // 1. MULTI SET
    // Rule broken: Allows duplicate values.
    // Underlying structure: Red-Black Tree (Sorted, O(log N))
    // ---------------------------------------------------------
    multiset<int> ms;
    
    ms.insert(10);
    ms.insert(20);
    ms.insert(10); // Duplicate allowed!
    ms.insert(10); 

    cout << "--- MULTI SET (Sorted, Duplicates Allowed) ---" << endl;
    for (int val : ms) cout << val << " "; // Prints: 10 10 10 20
    cout << "\n\n";

    // ---------------------------------------------------------
    // 2. UNORDERED SET
    // Rule broken: No longer sorted. 
    // Underlying structure: Hash Table (Ultra Fast, O(1) Time)
    // ---------------------------------------------------------
    unordered_set<int> us;
    
    us.insert(30);
    us.insert(10);
    us.insert(20);
    us.insert(10); // Duplicate ignored (Must be unique)

    cout << "--- UNORDERED SET (Unique, Random Order) ---" << endl;
    for (int val : us) cout << val << " "; // Order is unpredictable!
    cout << "\n";

    return 0;
}