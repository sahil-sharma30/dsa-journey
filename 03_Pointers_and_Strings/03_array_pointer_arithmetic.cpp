#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30};
    
    // 1. Array Pointer Validation
    cout << "Base address (arr): " << arr << endl;
    cout << "0th index address: " << &arr[0] << endl;

    // 2. Pointer Arithmetic
    cout << "Index 0: " << *arr << endl;
    cout << "Index 1: " << *(arr + 1) << endl;
    cout << "Index 2: " << *(arr + 2) << endl;

    return 0;
}