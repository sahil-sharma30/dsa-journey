#include <iostream>
using namespace std;

// Algorithm 1: N Factorial
// Recurrence Relation: f(n) = n * f(n-1)
int factorial(int n) {
    // BASE CASE: Prevents Stack Overflow
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Algorithm 2: Sum of N numbers
// Recurrence Relation: f(n) = n + f(n-1)
int sum(int n) {
    // BASE CASE
    if (n == 1) {
        return 1;
    }
    return n + sum(n - 1);
}

int main() {
    int n = 5;
    
    cout << "Factorial of " << n << " is: " << factorial(n) << endl;
    cout << "Sum of first " << n << " numbers is: " << sum(n) << endl;
    
    return 0;
}