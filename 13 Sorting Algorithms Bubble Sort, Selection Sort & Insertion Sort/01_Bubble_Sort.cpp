#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size(), swapCount = 0;
    
    // Outer loop controls the total passes
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false; // Reset the flag at the start of every new pass

        // Inner loop pushes the heaviest element to the right; shrinks by 'i' each pass
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if adjacent elements are out of order
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j+1]);
                swapCount++;

                swapped = true;
            }
        }

        // Early exit: if no swaps occurred
        if (swapped == false)
        {
            break;
        }
    }

    // Print final sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Swap Count: " << swapCount << endl;
}

int main()
{
    vector<int> arr = {1, 9, 2, 8, 3};
    
    bubbleSort(arr);

    return 0;
}
