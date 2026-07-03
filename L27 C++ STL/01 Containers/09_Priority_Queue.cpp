#include <iostream>
#include <queue>
#include <vector> // Required for the Min-Heap syntax
using namespace std;

int main() {
    // 1. MAX HEAP (Default Configuration)
    // The largest element always fights its way to the front.
    priority_queue<int> maxHeap;
    
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(20);
    
    cout << "--- MAX HEAP ---" << endl;
    cout << "Top element: " << maxHeap.top() << endl; // Outputs 50
    
    // Physically removes 50. The tree restructures itself in O(log N) time.
    maxHeap.pop(); 
    
    cout << "New Top after pop: " << maxHeap.top() << endl; // Outputs 20


    // 2. MIN HEAP (Custom Configuration)
    // The smallest element always fights its way to the front.
    // Syntax: <Data Type, Container Type, Comparison Logic>
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(20);
    
    cout << "\n--- MIN HEAP ---" << endl;
    cout << "Top element: " << minHeap.top() << endl; // Outputs 10
    
    minHeap.pop(); // Removes 10
    
    cout << "New Top after pop: " << minHeap.top() << endl; // Outputs 20

    return 0;
}