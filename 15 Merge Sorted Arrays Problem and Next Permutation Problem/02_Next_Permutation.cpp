#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int pivot = -1;
    
    // STEP 1: Find the Pivot
    // Scan right-to-left. Find the first number that breaks the descending trend.
    // Starting at n-2 prevents out-of-bounds memory access on i+1.
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }

    // STEP 2: Find the Successor and Swap
    // If pivot is -1, the array is already at its max permutation. Skip to Step 3.
    if (pivot != -1)
    {
        // Scan right-to-left again to find the first number strictly greater than the pivot.
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
    }

    // STEP 3: Reverse the Tail
    // The tail is currently in descending order (maximum value). 
    // Reverse it to ascending order to make it the immediate next permutation.
    int left = pivot + 1;
    int right = n - 1;
    while (left < right)
    {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

void printArray(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums{2, 0, 5, 4, 3, 1};

    nextPermutation(nums);
    printArray(nums);

    return 0;
}


//Hello :)