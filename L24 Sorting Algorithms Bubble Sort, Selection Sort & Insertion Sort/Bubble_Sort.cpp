#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    int temp, swapCount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false; // Reset the flag at the start of every new pass

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount++;

                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }

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
    int n = arr.size();
    int temp;
    int swapCount = 0;

    bubbleSort(arr, n);

    return 0;
}
