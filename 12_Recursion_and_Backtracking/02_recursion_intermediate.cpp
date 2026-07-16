#include <iostream>
using namespace std;

// 1. FIBONACCI (ITERATIVE)
// Strict O(N) Time | O(1) Space implementation
// We avoid the Call Stack entirely, preventing Stack Overflow and O(2^N) time bloat.
int fib(int n)
{
    int a = 0, b = 1;
    int ans;

    if (n == 0) return 0;
    if (n == 1) return 1;

    for (int i = 0; i < n - 1; i++)
    {
        ans = a + b; 
        a = b;       
        b = ans;     
    }
    
    return ans;
}

// 2. IS ARRAY SORTED (RECURSIVE)
bool isSorted(int arr[], int n)
{
    // Base Cases
    if (n == 0 || n == 1)
    {
        return true;
    }

    // Defect Check
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return isSorted(arr + 1, n - 1);
    }
}

// 3. BINARY SEARCH (RECURSIVE)
bool binarySearch(int arr[], int st, int end, int target)
{
    // BASE CASE FIRST
    if (st > end)
    {
        return false;
    }

    // CALCULATE MID
    int mid = st + (end - st) / 2;

    // SUCCESS CASE
    if (arr[mid] == target)
    {
        return true;
    }

    // RECURSIVE STEPS
    if (target > arr[mid])
    {
        return binarySearch(arr, mid + 1, end, target);
    }
    else
    {
        return binarySearch(arr, st, mid - 1, target);
    }
}

int main()
{
    // Test 1: Fibonacci
    int n = 7;
    cout << "Fibonacci of " << n << " is: " << fib(n) << "\n\n";

    // Test 2: IsSorted
    int arr[] = {1, 2, 10, 4, 5};
    int arrSize = 5; 
    
    cout << "Is array {1, 2, 10, 4, 5} sorted? : ";
    if (isSorted(arr, arrSize)) {
        cout << "True\n\n";
    } else {
        cout << "False\n\n";
    }

    // Test 3: Binary Search
    int arr2[] = {2, 4, 6, 10, 14, 18};
    int target = 14;
    int st = 0;
    int end = (sizeof(arr2) / sizeof(int)) - 1;

    cout << "Searching for " << target << " in arr2 : ";
    if (binarySearch(arr2, st, end, target)) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}