#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    
    // Outer loop tracks the boundary of the permanently sorted left section
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; // Assume the current slot holds the smallest remaining value

        // search the entire unsorted right side
        for (int j = i + 1; j < n; j++)
        {
            // Lock onto a new target if we find a smaller element
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j; 
            }
        }
        
        // Execute exactly ONE swap per pass
        swap(arr[i], arr[minIndex]);
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

    selectionSort(arr);
    printArray(arr);

    return 0;
}
