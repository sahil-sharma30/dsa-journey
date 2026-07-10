# Lecture 18: Search in Rotated Sorted Array

## Problem Statement
Given an integer array `arr` of size `N` that is sorted in ascending order but randomly rotated at an unknown pivot, find the index of a given `target`. If the target is not found, return `-1`. 

The algorithm must run in $O(\log N)$ time complexity, which means strict Binary Search must be used. Linear Search $O(N)$ is not acceptable.

---

## The Thinking Process 

### 1. Why Standard Binary Search Fails
A standard Binary Search assumes a single, unbroken ascending line. In a rotated array, the data is broken into two separate ascending blocks (e.g., `[4, 5, 6, 7]` and `[0, 1, 2, 3]`). If you blindly move left or right based strictly on the midpoint's value, you will bypass the target because the numbers reset at the pivot.

### 2. The Core Insight: The Clean Line
Whenever you slice a rotated array in half using a `mid` pointer, **one of those two halves will always be perfectly sorted**. 
The algorithm must first mathematically prove which side is the "Clean Line" before making any decisions about where to search.

### 3. Step-by-Step Execution
* **The Bullseye Check:** First, check if `arr[mid] == target`. If yes, return the index immediately.
* **Identify the Clean Line:** Compare `arr[mid]` to the end pointers. If `arr[mid] <= arr[end]`, the right side is perfectly sorted. If false, the left side is perfectly sorted.
* **Build the Trap (Boundary Check):** Once the Clean Line is identified, ask: *Does the target physically fit inside the minimum and maximum boundaries of this perfect line?*
* **Execute the Shift:** If the target fits inside the Clean Line, throw away the chaotic half. If the target does *not* fit inside the Clean Line, throw away the Clean Line and search the chaotic half.

---

## The C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(const vector<int> &arr, int tar) {
    int st = 0, end = arr.size() - 1;
    
    while (st <= end) {
        // Prevent integer overflow during midpoint calculation
        int mid = st + (end - st) / 2;
        
        // 1. The Bullseye Check
        if (arr[mid] == tar) {
            return mid;
        }
        
        // 2. Identify the Clean Line: Is the Right side sorted?
        if (arr[mid] <= arr[end]) {
            // 3. The Trap: Does the target fit in this clean right line?
            if (arr[mid] <= tar && tar <= arr[end]) {
                st = mid + 1;  // Target is here, discard left half
            } else {
                end = mid - 1; // Target is NOT here, discard right half
            }
        } 
        // 4. If the Right side isn't sorted, the Left side MUST be sorted
        else {
            // 5. The Trap: Does the target fit in this clean left line?
            if (arr[st] <= tar && tar <= arr[mid]) {
                end = mid - 1; // Target is here, discard right half
            } else {
                st = mid + 1;  // Target is NOT here, discard left half
            }
        }
    }
    
    // Fallback if target does not exist in the array
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int tar = 0;
    
    cout << "Target Index: " << BinarySearch(arr, tar) << endl;
    return 0;
}
V