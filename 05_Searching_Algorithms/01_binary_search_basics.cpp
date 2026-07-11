#include <iostream>
#include <vector>
using namespace std;

void linearSearch(const vector<int> &arr, int target) {
    bool found = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            cout << arr[i] << " is the matching no. at position " << i+1 << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No match." << endl;
    }
}

int binarySearchIterative(const vector<int> &arr, int tar) {
    int st = 0, end = arr.size() - 1;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (tar > arr[mid]) {
            st = mid + 1;
        } else if (tar < arr[mid]) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

// 3. Recursive Binary Search
int binarySearchRecursive(const vector<int> &arr, int tar, int st, int end) {
    if(st <= end){
        int mid = st + (end-st)/2;
        if(tar > arr[mid]){
            return binarySearchRecursive(arr, tar, mid+1, end);
        } else if(tar < arr[mid]){
            return binarySearchRecursive(arr, tar, st, mid-1);
        } else{
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int> arr1 = {8, 2, 6, 4, 9};
    linearSearch(arr1, 6);

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};
    cout << "Target found at index: " << binarySearchIterative(arr2, 12) << endl;
    cout << binarySearchRecursive(arr2, 5, 0, arr2.size() - 1) << endl;

    return 0;
}