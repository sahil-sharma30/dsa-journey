#include <iostream>
#include <algorithm> // CRITICAL: Required to use sort()
#include <vector>
using namespace std;

int main()
{
    int arr[] = {5, 2, 8, 1, 9};
    // Correct way to get array length in C++
    int n = sizeof(arr) / sizeof(arr[0]);

    // 1. Standard Array Sort (Ascending)
    // Syntax: sort(start_address, end_address_after_last_element)
    sort(arr, arr + n);
    for (auto s : arr)
    {
        cout << s << " ";
    }
    cout << endl;

    // 2. Array Sort with a Comparator (Descending)
    // greater<int>() is an inbuilt functor that reverses the default sorting logic
    sort(arr, arr + n, greater<int>());
    for (auto s : arr)
    {
        cout << s << " ";
    }
    cout << endl;

    // 3. Vector Sort
    // We use iterators .begin() and .end() instead of raw memory addresses
    vector<int> v = {4, 1, 7, 3};
    sort(v.begin(), v.end());

    return 0;
}