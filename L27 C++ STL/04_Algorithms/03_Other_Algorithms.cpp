#include <iostream>
#include <vector>
#include <algorithm> // Required for reverse, next_permutation, swap, min, max
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};

    // 1. REVERSE (O(N) time)
    // Physically flips the elements in memory.

    reverse(v.begin(), v.end());

    cout << "After Reverse: ";
    for (int val : v)
        cout << val << " "; // Prints: 3 2 1
    cout << "\n\n";

    // 2. NEXT PERMUTATION (O(N) time)
    // Rearranges elements into the next lexicographically greater sequence.

    vector<int> v2 = {1, 3, 2};
    next_permutation(v2.begin(), v2.end());

    cout << "Next Permutation of {1, 3, 2}: ";
    for (int val : v2)
        cout << val << " "; // Prints: 2 1 3
    cout << "\n\n";

    // 3. SWAP, MIN, MAX (O(1) time)
    // Basic utility operations.

    int a = 10, b = 25;

    swap(a, b); // 'a' is now 25, 'b' is 10

    cout << "After Swap: a = " << a << ", b = " << b << endl;
    cout << "Min: " << min(a, b) << endl;
    cout << "Max: " << max(a, b) << endl;

    return 0;
}