#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;      // tracks 0s at the start
    int mid = 0;      // scout pointer to scan the array
    int high = n - 1; // tracks 2s at the end

    // <= because the element at 'high' is still unchecked
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            // found 0, send to left
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            // found 1, leave it in the middle
            mid++;
        }
        else if (arr[mid] == 2)
        {
            // found 2, send to right
            swap(arr[mid], arr[high]);
            high--;
            // DON'T mid++ here! The newly swapped element needs to be checked
        }
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
    vector<int> arr = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};

    sortColors(arr);
    printArray(arr);

    return 0;
}