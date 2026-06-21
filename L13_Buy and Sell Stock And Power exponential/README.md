# Lecture 13: Arrays and Binary Exponentiation

## Part 1: Best Time to Buy and Sell Stock (LeetCode #121)

### The Core Concept
The goal is to maximize profit by choosing a single day to buy and a single future day to sell. 

### The Algorithmic Logic
Instead of using nested loops ($O(N^2)$) to compare every possible buy/sell combination, we can solve this in a single pass using two tracker variables:
1. **`minPrice`:** Tracks the absolute lowest price seen so far. (Initialize with `INT_MAX`).
2. **`maxProfit`:** Tracks the largest difference between the current day's price and the `minPrice`. (Initialize with `0`).

* **Time Complexity:** $O(N)$ — We traverse the array exactly once.
* **Space Complexity:** $O(1)$ — We only use two integer variables for tracking.

---

## Part 2: Binary Exponentiation - Pow(x, n) (LeetCode #50)

### The Core Concept
Calculating $x^n$ using a standard `for` loop takes $O(N)$ time. If the power is 1 billion, the loop runs 1 billion times, causing a Time Limit Exceeded (TLE) error. 

**Binary Exponentiation** reduces this to **$O(\log N)$ time** by leveraging the binary representation of the exponent. 
* **The Math Trick:** If the power is odd, pull one base out and multiply it to the answer. Then, square the base and halve the power. 
* **The Binary Reality:** Halving the power (`BF / 2`) is the exact mathematical equivalent of shifting to the next binary bit.

* **Time Complexity:** $O(\log N)$ 
* **Space Complexity:** $O(1)$

### ⚠️ The Engineering Viva Traps

**Examiner Question 1:** *"Why did you use a `long long` for the power instead of a standard `int`?"*
> **Your Answer:** *"To prevent an Integer Overflow. The lowest possible negative integer in C++ is `-2,147,483,648`. If the system passes that as the power, and I try to flip it to positive using `-n`, it exceeds the maximum positive integer limit (`2,147,483,647`) and crashes. `long long` gives me the 64-bit architecture needed to safely hold the flipped number."*

**Examiner Question 2:** *"Why is this $O(\log N)$?"*
> **Your Answer:** *"Because the `while` loop doesn't run $N$ times. It only runs for the exact number of bits required to write $N$ in binary. A number like 1,000,000 only takes about 20 bits in binary, meaning our loop only takes 20 steps to calculate $x^{1000000}$."*
