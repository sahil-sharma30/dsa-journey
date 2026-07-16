#include <iostream>
using namespace std;

// Strict O(N) Time | O(1) Space implementation
// We avoid the Call Stack entirely, preventing Stack Overflow and O(2^N) time bloat.
int fib(int n)
{
    // Variables to track only the last two numbers.
    // This allows O(1) space instead of using an O(N).
    int a = 0, b = 1;
    int ans;

    // Base Cases
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    // Loop exactly N-1 times to shift the window forward.
    for (int i = 0; i < n - 1; i++)
    {
        ans = a + b; // Calculate the next number in the sequence
        a = b;       // Shift 'a' forward
        b = ans;     // Shift 'b' forward
    }

    return ans;
}

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

int main()
{
    int n = 7;

    int arrsize = 5;
    int arr[] = {1, 2, 10, 4, 5};

    cout << "Fibonacci of " << n << " is: " << fib(n) << endl;

    cout << isSorted(arr, arrsize);

    return 0;
}