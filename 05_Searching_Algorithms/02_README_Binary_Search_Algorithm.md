# Lecture 17: Binary Search Algorithm & Time Complexity

## 1. The Fundamental Constraint
Binary Search mathematically requires the data to be **sorted** (ascending or descending). 
You cannot perform a Binary Search on chaotic, unsorted data. If the array is unsorted, you are forced to use a Linear Search ($O(N)$) or sort it first.

* **Linear Search:** Sweeps every element one by one. Best case $\Omega(1)$ (if target is at index 0 and we use a `break` statement), Worst case $O(N)$.
* **Binary Search:** Eliminates half of the search space at every step. Time complexity is $O(\log N)$.

## 2. The Integer Overflow Trap
A standard 32-bit C++ integer has a maximum limit of `2,147,483,647`. 
Using the standard formula `int mid = (st + end) / 2;` will cause a silent memory overflow and a Segmentation Fault if `st` and `end` are exceptionally large.

**The Production Fix:**
```cpp
int mid = st + (end - st) / 2;