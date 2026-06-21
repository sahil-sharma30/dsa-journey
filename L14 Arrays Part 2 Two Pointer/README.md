# Lecture 14: The Two-Pointer Approach 

## The Core Concept
The **Two-Pointer Approach** is an algorithmic technique used to drastically reduce Time Complexity when searching arrays. Instead of using nested loops to compare every single element against every other element, we use two integer variables (acting as "pointers" or index trackers) to squeeze the array from both ends.

## Problem: Container With Most Water (LeetCode #11)
**The Goal:** Given an array of heights, find two lines that together with the x-axis form a container that holds the maximum amount of water.

### 1. The Brute Force Way (The Rookie Mistake)
* **Logic:** Use a nested `for` loop to calculate the area between *every single possible pair* of lines.
* **Time Complexity:** $O(N^2)$ — Will cause a Time Limit Exceeded (TLE) error on large datasets.
* **Space Complexity:** $O(1)$

### 2. The Optimal Way (Two-Pointer Squeeze)
* **Logic:** Start with the maximum possible width (one pointer at index `0`, one at the `last` index). Calculate the area. To find a potentially larger area, always move the pointer that points to the **shorter** line inward.
* **Time Complexity:** $O(N)$ — We traverse the array exactly once.
* **Space Complexity:** $O(1)$ — We only use a few integer variables (`left`, `right`, `maxWater`).

## ⚠️ The Engineering Viva Trap
**Examiner Question:** *"Why do you specifically move the pointer of the shorter line? Why not the taller line?"*

**Your Answer:** *"Because the total area is strictly bottlenecked by the shorter line. If I move the taller line inward, the width decreases, and the height can NEVER get taller than my current short line. The area is guaranteed to shrink. Moving the shorter line is the only mathematical chance of finding a taller boundary to offset the loss of width."*