#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The Custom Rule
bool comparator(pair<int, int> p1, pair<int, int> p2) {
    // Phase 1: Sort by the .second element (ascending)
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    
    // Phase 2: If .second elements are exactly equal
    // Sort by the .first element (ascending)
    if (p1.first < p2.first) return true;
    else return false;
}

int main() {
    vector<pair<int, int>> vec = {{3, 1}, {2, 1}, {7, 1}, {5, 2}};

    sort(vec.begin(), vec.end(), comparator);

    cout << "--- Sorted Pairs ---" << endl;
    for (auto p : vec) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}