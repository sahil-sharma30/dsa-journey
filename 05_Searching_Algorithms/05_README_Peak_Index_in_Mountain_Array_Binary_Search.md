# Lecture 19: Peak Index in a Mountain Array

## Problem Statement
Given an integer array `arr` that is guaranteed to be a mountain (strictly increasing to a peak, then strictly decreasing), return the index of the peak element. The algorithm must run in $O(\log N)$ time complexity.

---

## The Thinking Process

### 1. The Core Insight: Hunting the Slope
In a standard Binary Search, we look for a straight line. In a mountain, straight lines do not exist. Instead, we must determine if our `mid` pointer is walking **uphill** or **downhill** by comparing it to its immediate neighbors.

### 2. Memory Protection (Segmentation Fault Prevention)
Because we must check `arr[mid - 1]` and `arr[mid + 1]`, starting our search at absolute index `0` or `arr.size() - 1` risks an Out of Bounds memory error. Since the peak mathematically cannot be the first or last element, we shrink the initial boundaries to protect the memory:
* `st = 1`
* `end = arr.size() - 2`

### 3. Step-by-Step Execution
* **The Peak Check:** If `arr[mid]` is strictly greater than both its left and right neighbors, it is the peak. Return `mid`.
* **The Uphill Condition:** If `arr[mid] > arr[mid - 1]`, we are walking up the mountain. The peak must be ahead of us. Throw away the left half (`st = mid + 1`).
* **The Downhill Condition:** If we aren't the peak and we aren't walking uphill, we mathematically must be walking downhill. The peak is behind us. Throw away the right half (`end = mid - 1`).

---
