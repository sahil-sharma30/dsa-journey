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
