#include <iostream>
#include <vector>
using namespace std;

int SingleElement(const vector<int> &arr)
{
    int n = arr.size();
    // 1. Edge Cases (Size 1 or extreme edges)
    if (n == 1)
    {
        return arr[0];
    }
    else if (arr[0] != arr[1])
    {
        return arr[0];
    }
    else if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }
    else
    {
        // 2. Search Space (Edges safely excluded)
        int st = 1, end = arr.size() - 2;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            // 3. Target Found
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            {
                return arr[mid];
            }
            // 4. Pattern Check via XOR
            else if (arr[mid] == arr[mid ^ 1]) 
            {
                st = mid + 1;
            }
            else 
            {
                end = mid - 1;
            }
        }
        return -1;
    }
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 8, 8};
    cout << "The single element is: " << SingleElement(arr) << endl;

    return 0;
}
