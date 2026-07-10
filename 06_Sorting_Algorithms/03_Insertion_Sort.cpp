#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    // Outer loop steps forward to pick up the next unsorted container
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i]; // The physical box in your hand
        int j = i - 1;     // Eyes scanning exactly one step to the left

        // scanning backward until i hit the boundary or a lighter block
        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j]; // Shift the heavy container right to make a gap

            j--; // Take a step backward down the wall
        }
        
        // place the box into the perfect gap once shifting stops
        arr[j + 1] = curr;
    }
}

void printArray(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {7, 2, 9, 1, 5};

    insertionSort(arr);
    printArray(arr);

    return 0;
}
