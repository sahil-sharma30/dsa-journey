# Lecture 12: Time and Space Complexity

## Core Concept
Time and Space Complexity is how we measure the efficiency of an algorithm, regardless of the hardware it runs on. We use **Big O Notation** to describe the absolute worst-case scenario.

## Time Complexity (Speed)
Measures how the runtime grows as the input size (N) grows.

* **O(1) - Constant Time:** The fastest. Takes the exact same amount of time regardless of input size. 
* **O(N) - Linear Time:** Time scales directly with input size. (Example: A single for loop traversing an array).
* **O(N^2) - Quadratic Time:** The danger zone. Time squares as input grows. (Example: Nested for loops).
* **O(log N) - Logarithmic Time:** Highly efficient for large datasets because it halves the search area at each step. 

## Space Complexity (Memory)
Measures the extra memory an algorithm needs to run, based on input size (N).

* **O(1) Space:** The algorithm only uses a fixed number of tracking variables. (The Gold Standard).
* **O(N) Space:** The algorithm requires creating a brand new array or data structure equal to the size of the original input.