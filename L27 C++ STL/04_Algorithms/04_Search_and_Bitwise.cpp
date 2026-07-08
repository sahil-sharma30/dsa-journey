#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    // Max and Min element
    // Finds maximum and minimum value in the array

    cout << "The maximum value is: " << *(max_element(vec.begin(), vec.end())) << endl;
    cout << "The minimum value is: " << *(min_element(vec.begin(), vec.end())) << endl;

    // Binary Search
    // Syntax: binary_search(v.begin(),v.end(),target)
    // target returns bool value, is target exist in the vector or not

    cout << binary_search(vec.begin(), vec.end(), 3) << endl;
    cout << endl;

    //Count Set Bits
    //Used to count no. of "1" bit in binary

    int n = 31;
    long int n1 = 31;
    long long int n2 = 31;

    cout << __builtin_popcount(n) << endl;
    cout << __builtin_popcountl(n1) << endl;
    cout << __builtin_popcountll(n2) << endl;

    return 0;
}