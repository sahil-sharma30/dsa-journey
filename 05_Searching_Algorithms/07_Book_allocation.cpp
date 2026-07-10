#include <iostream>
#include <vector>
using namespace std;

bool isValid(const vector<int> &arr, int n, int m, int mid)
{
    int studentCount = 1;
    int currentPages = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > mid){
            return false;
        }
         
        if(currentPages + arr[i] <= mid){
            currentPages += arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m){
                return false;
            }
            currentPages = arr[i];
        }
    }
    return true;
}

int allocateBooks(const vector<int> &arr, int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int st = 0, end = sum, ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(arr, n, m, mid))
        {
            ans = mid;     // It worked! Save the answer.
            end = mid - 1; // Throw away the right half to hunt for a tighter limit.
        }
        else
        {
            st = mid + 1; // It failed! Limit was too strict. Throw away the left half.
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;

    cout<< allocateBooks(arr,n,m)<<endl;
    return 0;
}
