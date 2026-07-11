#include <iostream>
using namespace std;

// --- NULL Pointers ---
void NullPointer() {
    cout << "\n--- NULL Pointer ---" << endl;
    int* ptr = NULL; 
    cout << "Value of ptr: " << ptr << endl;
    // NULL pointer doesn't store anything.
}

// --- Pass by Value vs Pass by Address ---
void updateValue(int x) {
    x = 0; 
}

void updateAddress(int* ptr) {
    *ptr = 0; 
}

void PassByReferenceAndValue() {
    cout << "\n--- Pass by Value vs Address ---" << endl;
    int health = 100;

    updateValue(health);
    cout << "After updateValue: " << health << endl;

    updateAddress(&health);
    cout << "After updateAddress: " << health << endl;
}

// --- Array Pointer Arithmetic ---
void ArrayPointerArithmetic() {
    cout << "\n--- Array Pointer Arithmetic ---" << endl;
    int arr[] = {10, 20, 30};
    
    // 1. Array Pointer Validation
    cout << "Base address (arr): " << arr << endl;
    cout << "0th index address: " << &arr[0] << endl;

    // 2. Pointer Arithmetic
    cout << "Index 0: " << *arr << endl;
    cout << "Index 1: " << *(arr + 1) << endl;
    cout << "Index 2: " << *(arr + 2) << endl;
}

int main() {
    NullPointer();
    PassByReferenceAndValue();
    ArrayPointerArithmetic();
    
    return 0;
}