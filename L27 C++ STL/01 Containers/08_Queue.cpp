#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Initialize an empty FIFO queue
    queue<int> q;
    queue<int> q2;

    // 1. push & emplace (Adding to the back of the line)
    q.push(10);
    q.push(20);
    q.emplace(30); // Constructs 30 directly in place

    // 2. size & empty (Checking state)
    cout << "Current Size: " << q.size() << endl;
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    // 3. front & pop (Reading and Removing)
    // The line is: [10 (front), 20, 30 (back)]
    cout << "Front element: " << q.front() << endl; // Reads 10 (First In)
    
    q.pop(); // Physically removes the 10 from the front (First Out)
    
    cout << "New front element: " << q.front() << endl; // Now reads 20

    // 4. swap (Exchanging memory)
    q2.swap(q); // 'q' hands all its data over to 'q2'
    
    cout << "\nAfter Swap:" << endl;
    cout << "q2 size: " << q2.size() << endl;
    cout << "q size: " << q.size() << endl;

    return 0;
}