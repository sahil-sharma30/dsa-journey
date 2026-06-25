#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Place scouts at the end of the actual numbers
    int p1 = m - 1;
    int p2 = n - 1;
    
    // Place the drop zone at the extreme right of arr1's empty space
    int index = m + n - 1;

    // Compare blocks and place the largest at the back to avoid overwriting arr1's data
    while (p1 >= 0 && p2 >= 0)
    {
        if (arr1[p1] >= arr2[p2])
        {
            arr1[index] = arr1[p1];
            index--;
            p1--;
        }
        else
        {
            arr1[index] = arr2[p2];
            index--;
            p2--;
        }
    }

    // Safety net: If arr2 still has blocks left, drop them into the remaining slots
    // (If p1 has blocks left, they are already perfectly sorted in place)
    while (p2 >= 0)
    {
        arr1[index] = arr2[p2];
        index--;
        p2--;
    }
}

void printArray(vector<int> &arr1)
{
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
}

int main()
{
    // arr1 has built-in empty space (zeros) at the back to fit arr2
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};
    
    // m and n represent the count of actual elements, ignoring the trailing zeros
    int m = 3;
    int n = 3;

    mergeArrays(arr1, arr2, m, n);
    printArray(arr1);

    return 0;
}
