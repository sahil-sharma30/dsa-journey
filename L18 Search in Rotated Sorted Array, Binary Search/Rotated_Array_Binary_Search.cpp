#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(const vector<int> &arr, int tar)
{
    int st = 0, end = arr.size() - 1;
    while (st <= end)
    {

        int mid = st + (end - st) / 2;
        if (arr[mid] == tar) {
            return mid;
        }
        if (arr[mid] <= arr[end])
        {                            // Right side sorted
            if (arr[mid] <= tar && tar <= arr[end])
            {
                st= mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        else
        {           //Left side sorted
            if (arr[st] <= tar && tar <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int tar = 3;

    cout << BinarySearch(arr, tar) << endl;
    return 0;
}
