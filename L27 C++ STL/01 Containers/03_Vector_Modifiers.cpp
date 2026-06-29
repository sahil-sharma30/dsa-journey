#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize a vector with some starting values
    vector<int> v = {10, 20, 30, 40, 50};

    // 1. insert: Adds elements at a specific position (using iterators)
    v.insert(v.begin() + 1, 15); 
    // Vector is now: {10, 15, 20, 30, 40, 50}

    // 2. erase: Removes elements from a specific position or range
    v.erase(v.begin() + 2); 
    // Removes the '20'. Vector is now: {10, 15, 30, 40, 50}

    // 3. empty: Checks if the vector has 0 elements (returns a boolean)
    cout << "Is vector empty? " << (v.empty() ? "Yes" : "No") << endl;

    // 4. clear: Deletes all elements in the vector
    v.clear(); 
    
    // Verify clear worked
    cout << "Size after clear(): " << v.size() << endl;
    cout << "Is vector empty now? " << (v.empty() ? "Yes" : "No") << endl;

    return 0;
}