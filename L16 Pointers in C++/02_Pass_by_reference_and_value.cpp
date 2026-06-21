#include <iostream>
using namespace std;

// 1. Pass by Value
void updateValue(int x) {
    x = 0; 
}

// 2. Pass by Address
void updateAddress(int* ptr) {
    *ptr = 0; 
}

int main() {
    int health = 100;

    updateValue(health);
    cout << "After updateValue: " << health << endl;

    updateAddress(&health);
    cout << "After updateAddress: " << health << endl;

    return 0;
}
