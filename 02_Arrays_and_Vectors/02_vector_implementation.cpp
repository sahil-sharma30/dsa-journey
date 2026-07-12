#include <iostream>
#include <vector>

using namespace std;

void vectorBasics() {
    vector<int> vec = {10, 20, 30};

    vec.push_back(40);
    vec.push_back(50);

    cout << "Elements: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Demonstrating Dynamic Memory Allocation
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    vec.pop_back();

    cout << "Front: " << vec.front() << endl;
    cout << "Back: " << vec.back() << endl;
}

// Practice Problem: Single Number (Leetcode 136)
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans ^= nums[i]; 
    }
    return ans;
}

int main() {
    cout << "Vector Functions" << endl;
    vectorBasics();

    cout << "\nSingle Number Problem" << endl;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Array: 4 1 2 1 2" << endl;
    cout << "Unique Number: " << singleNumber(nums) << endl;

    return 0;
}