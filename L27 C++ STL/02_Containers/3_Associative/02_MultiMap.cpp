#include <iostream>
#include <map> 
using namespace std;

int main() {
    // Architecture: Red-Black Tree (Automatically sorted)
    // Core Trait: Allows duplicate keys.
    multimap<string, int> m;
    
    m.emplace("tv", 100);
    m.emplace("tv", 150); // Valid: Both "tv" keys will exist
    m.emplace("laptop", 200);

    // The [] operator is strictly forbidden in MultiMaps. 
    // The compiler cannot guess which duplicate key you want to modify.
    
    cout << "Total 'tv' entries: " << m.count("tv") << "\n\n";

    for (auto p : m) {
        cout << p.first << " : " << p.second << "\n";
    }

    return 0;
}