# Lecture 20: Single Element in a Sorted Array

## Problem Statement
Given a sorted array `arr` where every element appears exactly twice except for one element which appears exactly once. Find the single element. The algorithm must run in $O(\log N)$ time and $O(1)$ space.

---

## The Thinking Process & Engineering Architecture

### 1. The Core Insight: The Broken Pattern
In an array of pairs, the indices follow a strict `(Even, Odd)` grouping pattern.
* **Left Half (Pattern Intact):** Before the single element, the first instance of a pair is always at an **Even** index, and the second instance is at the adjacent **Odd** index (`mid + 1`).
* **Right Half (Pattern Broken):** The insertion of the single element shifts the entire right side of the array by one position. The pairs now sit at `(Odd, Even)` indices.

### 2. Memory Protection (Edge Cases)
Because the `while` loop checks `mid - 1` and `mid + 1`, we must prevent out-of-bounds errors (Segmentation Faults). We manually handle the absolute edges before the loop begins:
* If `arr[0] != arr[1]`, the single element is at index `0`.
* If `arr[n-1] != arr[n-2]`, the single element is at the last index.
* We then safely shrink our search boundaries to `st = 1` and `end = n - 2`.

### 3. The Bitwise XOR Optimization (`^`)
Instead of writing a massive `if/else` block to check if `mid` is Even or Odd, we use `mid ^ 1`.
* If `mid` is **Even**, `mid ^ 1` gives `mid + 1` (Checks Right).
* If `mid` is **Odd**, `mid ^ 1` gives `mid - 1` (Checks Left).
This single mathematical operation instantly calculates the exact index where the duplicate partner *should* be if the pattern is still intact.

---

## The C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int SingleElement(const vector<int> &arr) {
    int n = arr.size();
    
    // 1. Edge Cases & Memory Protection
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    // 2. Search Space (Edges safely excluded)
    int st = 1, end = n - 2;
    
    while (st <= end) {
        int mid = st + (end - st) / 2;
        
        // 3. Target Found: Different from BOTH neighbors
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid]; 
        }
        
        // 4. Pattern Check via XOR optimization
        if (arr[mid] == arr[mid ^ 1]) {
            st = mid + 1;  // Pattern intact, single element is to the right
        } else {
            end = mid - 1; // Pattern broken, single element is to the left
        }
    }
    
    return -1;
}
