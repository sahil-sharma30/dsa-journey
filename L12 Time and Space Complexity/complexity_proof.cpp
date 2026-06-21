#include <iostream>
using namespace std;

int main() {
    int n = 5;

    // 1. O(N) Time Complexity (Linear)
    // The loop runs exactly 'n' times. (5 prints)
    cout << "--- O(N) Traversal ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Step " << i << endl;
    }
    
    cout << "\n";

    // 2. O(N^2) Time Complexity (Quadratic)
    // The inner loop runs 'n' times for EVERY single spin of the outer loop.
    // Total runs: n * n (25 prints)
    cout << "--- O(N^2) Traversal ---" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "(" << i << ", " << j << ") ";
        }
        cout << endl; // Drops to a new line after the inner loop finishes
    }

    return 0;
}