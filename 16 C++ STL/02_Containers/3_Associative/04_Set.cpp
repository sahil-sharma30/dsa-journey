#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // 1. insert
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    
    cout << "--- Set Contents ---" << endl;
    for (int val : s) {
        cout << val << " "; // 10 20 30 40 50
    }
    cout << "\n\n";

    // 2. count & find
    cout << "Does 20 exist? " << s.count(20) << endl;
    if (s.find(30) != s.end()) {
        cout << "30 found in memory!\n" << endl;
    }

    // 3. LOWER BOUND & UPPER BOUND 
    // Because the set is a tree, these run in ultra-fast O(log N) time.
    
    // lower_bound(X): Returns an iterator to the first element >= X
    auto it_lower = s.lower_bound(25); 
    cout << "Lower bound of 25 (first element >= 25): " << *it_lower << endl; // Prints 30

    auto it_lower_exact = s.lower_bound(30); 
    cout << "Lower bound of 30 (first element >= 30): " << *it_lower_exact << endl; // Prints 30

    // upper_bound(X): Returns an iterator to the first element STRICTLY > X
    auto it_upper = s.upper_bound(30);
    cout << "Upper bound of 30 (first element > 30): " << *it_upper << endl; // Prints 40


    // 4. erase (Cleaning up)
    s.erase(10); 
    cout << "\nSize after erase: " << s.size() << endl;

    return 0;
}