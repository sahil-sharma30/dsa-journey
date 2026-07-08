#include <iostream>
#include <vector>
#include <utility> // Standard header for std::pair
using namespace std;

int main() {
    // 1. Basic Pair
    pair<string, int> p1 = {"Sahil", 7};
    cout << "Basic Pair: " << p1.first << ", " << p1.second << "\n\n";

    // 2. Nested Pair
    pair<int, pair<char, int>> p2 = {1, {'s', 3}};
    cout << "Nested Pair:\n";
    cout << p2.first << "\n";
    cout << p2.second.first << "\n";
    cout << p2.second.second << "\n\n";

    // 3. Vector of Pairs & Insertion Differences
    vector<pair<int, int>> vec = {{1, 2}, {2, 3}, {3, 4}};
    
    // push_back requires explicit curly braces {} to construct the pair first
    vec.push_back({4, 5});     
    
    // emplace_back constructs the pair strictly in-place (slightly more optimized)
    vec.emplace_back(5, 6);    

    cout << "Vector of Pairs:\n";
    for(auto p : vec) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}