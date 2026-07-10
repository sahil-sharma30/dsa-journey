#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Initialize an empty vector
    vector<int> vec;

    // 1. push_back & emplace_back (Adding elements)
    vec.push_back(10);
    vec.push_back(20);
    vec.emplace_back(30); // emplace_back is slightly faster. It constructs the element directly in memory instead of copying it.

    // 2. front & back (Viewing ends)
    cout << "First element: " << vec.front() << endl; // 10
    cout << "Last element: " << vec.back() << endl;   // 30

    // 3. at() vs [] (Accessing specific elements)
    cout << "Index 1 using []: " << vec[1] << endl;      // 20 (Fast, but unsafe. Will crash silently if out of bounds)
    cout << "Index 1 using at(): " << vec.at(1) << endl; // 20 (Slower, but safe. Throws a catchable error if out of bounds)

    // 4. pop_back (Removing the last element)
    vec.pop_back();                                               // Destroys the '30' at the end
    cout << "New last element after pop: " << vec.back() << endl; // 20

    // 5. size & capacity (Memory tracking)
    // Size = How many actual numbers are currently inside.
    // Capacity = How much total memory space the vector has reserved in the background.
    cout << "Current Size: " << vec.size() << endl; // 2
    cout << "Current Capacity: " << vec.capacity() << endl;

    return 0;
}