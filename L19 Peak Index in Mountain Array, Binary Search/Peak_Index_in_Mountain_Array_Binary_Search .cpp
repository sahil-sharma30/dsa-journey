#include <iostream>
#include <vector>
using namespace std;

int PeakIndex(const vector<int> &arr)
{
    // Safe boundaries to prevent checking out-of-bounds indices
    int st = 1, end = arr.size() - 2;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        // Peak found: greater than both neighbors
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        // Uphill slope: peak is to the right
        else if (arr[mid] > arr[mid - 1])
        {
            st = mid + 1;
        }
        // Downhill slope: peak is to the left
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {0, 3, 8, 9, 5, 2};

    cout << "The Peak index is: " << PeakIndex(arr) << endl;
    return 0;
}
