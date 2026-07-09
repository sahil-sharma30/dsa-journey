#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// THE ARCHITECTURE OF A FUNCTOR
// A functor is just a standard Class or Struct that overloads the () operator.
// This allows an object to behave exactly like a function.

class MultiplyBy {
    int factor; // Functors can remember "state" (unlike normal functions)
public:
    MultiplyBy(int f) {
        factor = f;
    }
    
    // Overloading the () operator
    int operator()(int val) const {
        return val * factor;
    }
};

int main() {
    // 1. Custom Functor usage
    MultiplyBy multiplyBy5(5);
    cout << "Functor Result: " << multiplyBy5(10) << "\n\n"; // Outputs 50

    // 2. Built-in STL Functor usage
    // <functional> header provides standard ones like greater, less, plus, etc.
    vector<int> v = {1, 5, 3, 2, 4};
    
    // greater<int>() is a functor passed to the sorting algorithm
    sort(v.begin(), v.end(), greater<int>()); 

    cout << "Sorted with built-in Functor: ";
    for (int num : v) {
        cout << num << " "; 
    }
    cout << "\n";

    return 0;
}