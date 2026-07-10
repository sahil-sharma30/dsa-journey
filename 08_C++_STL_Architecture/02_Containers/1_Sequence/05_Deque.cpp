#include <iostream>
#include <deque>
using namespace std;

int main() {
    // 1. Initialization
    deque<int> d = {1, 2, 3};

    // 2. Adding Elements (Fast at BOTH ends)
    d.push_back(4);       // {1, 2, 3, 4}
    d.push_front(0);      // {0, 1, 2, 3, 4}
    
    d.emplace_front(-1);  // {-1, 0, 1, 2, 3, 4}
    d.emplace_back(5);    // {-1, 0, 1, 2, 3, 4, 5}

    // 3. Removing Elements
    d.pop_back();         // Destroys '5'
    d.pop_front();        // Destroys '-1'
    // Current Deque: {0, 1, 2, 3, 4}

    // 4. Random Access (SUPERPOWER: Lists cannot do this!)
    cout << "Element at index 2: " << d[2] << endl; 

    // 5. Size and Iteration
    cout << "Current Deque Size: " << d.size() << endl;

    cout << "Iterating through deque: ";
    for(int i = 0; i < d.size(); i++) {
        // Because of random access, we can use standard indexes!
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}