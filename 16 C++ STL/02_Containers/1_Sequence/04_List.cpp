#include <iostream>
#include <list>
using namespace std;

int main() {
    
    list<int> l = {1, 2, 3};

    // 2. Adding Elements (Fast at BOTH ends)
    l.push_back(4);       // List: {1, 2, 3, 4}
    l.push_front(0);      // List: {0, 1, 2, 3, 4}
    
    // emplace does the exact same thing but constructs in-place (slightly faster)
    l.emplace_front(-1);  // List: {-1, 0, 1, 2, 3, 4}
    l.emplace_back(5);    // List: {-1, 0, 1, 2, 3, 4, 5}

    // 3. Removing Elements
    l.pop_back();         // Destroys the '5'
    l.pop_front();        // Destroys the '-1'
    // Current List: {0, 1, 2, 3, 4}

    // 4. Accessing Ends (Cannot use l[0] or l.at(0) on a list!)
    cout << "Front element: " << l.front() << endl; // 0
    cout << "Back element: " << l.back() << endl;   // 4

    // 5. The rest of the functions (size, erase, clear, begin, end) 
    // work EXACTLY the same as they do in Vectors.
    cout << "Current List Size: " << l.size() << endl;

    cout << "Iterating through list: ";
    for(auto it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}