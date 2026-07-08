#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Initialize an empty LIFO stack
    stack<int> s;
    stack<int> s2;

    // 1. push & emplace (Adding to the top)
    s.push(10);
    s.push(20);
    s.emplace(30); // Constructs 30 directly in place (slightly more efficient than push)

    // 2. size & empty (Checking state)
    cout << "Current Size: " << s.size() << endl;
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;

    // 3. top & pop (Reading and Removing - LIFO in action)
    cout << "Top element: " << s.top() << endl; // Reads 30 (Last In)
    s.pop(); // Physically destroys the 30 (First Out)
    
    cout << "New top element: " << s.top() << endl; // Now reads 20

    // 4. swap (Exchanging memory)
    s2.swap(s); // 's' gives all its data to 's2' instantly
    
    cout << "\nAfter Swap:" << endl;
    cout << "s2 size: " << s2.size() << endl;
    cout << "s size: " << s.size() << endl;

    return 0;
}