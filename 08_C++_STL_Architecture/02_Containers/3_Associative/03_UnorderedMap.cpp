#include <iostream>
#include <unordered_map> 
using namespace std;

int main() {
    // Architecture: Hash Table (Unsorted, stored in random buckets)
    // Core Trait: Blisteringly fast O(1) average operations.
    unordered_map<string, int> m;
    
    m.emplace("apple", 100);
    m.emplace("banana", 200);
    m.emplace("cherry", 300);

    // The worst-case time complexity is actually O(N). 
    // This only happens during a rare "Hash Collision" (all data hits the same bucket).

    // Keys are strictly unique, so the [] operator works perfectly.
    m["apple"] = 999;       

    for (auto p : m) {
        cout << p.first << " : " << p.second << "\n"; 
    }

    return 0;
}