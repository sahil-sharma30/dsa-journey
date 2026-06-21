# Painter's Partition Problem (Binary Search on Answers)

**The Core Concept:**
This algorithm is mathematically identical to the Book Allocation problem. Instead of minimizing the maximum pages read by a student, we are minimizing the maximum time spent by any single painter. Assume 1 unit of board length takes 1 unit of time to paint.

### 1. Defining the Optimized Search Space
We must define the absolute lowest and highest possible time limits.
* **Best-Case Scenario (`st`):** The single largest board (`maxBoard`). Even if we had an infinite number of painters, one painter still has to paint the largest board alone. It is physically impossible to finish the job faster than that.
* **Worst-Case Scenario (`end`):** The total sum of all boards (`sum`). This happens if only 1 painter has to paint every single board.
* **The Optimization:** We calculate both `maxBoard` and `sum` in a single `for` loop, ensuring we only walk the array once ($O(N)$ time) before starting the Binary Search.

### 2. The `isValid()` Simulation (The Shift Change Test)
For every `mid` time limit the Binary Search generates, we run a physical simulation to see if that strict limit works for `M` painters.

**The Rules of the Simulation:**
1. **The Safe Workload:** If adding the current board keeps the painter's total time `<= mid`, add the board to their workload and move to the next.
2. **The Shift Change:** If adding the board forces the painter to strictly exceed `mid`, their shift is over. We bring in a new painter (`painterCount++`) and hand them the new board.
3. **The Victory/Fail Condition:** If we run out of allowed painters (`painterCount > M`), the time limit is too strict (`return false`). If we process every board successfully, the limit works (`return true`).

### 3. The Optimized C++ Engine

```cpp
#include <iostream>
#include <vector>
using namespace std;

// ENGINE 1: The Physical Simulation -> O(N)
bool isValid(const vector<int> &boards, int n, int m, int mid) {
    int painterCount = 1;
    int currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        // Safe Workload: Painter can take this board without exceeding limit
        if (currentTime + boards[i] <= mid) {
            currentTime += boards[i];
        } 
        // Shift Change: Painter is full, bring in the next painter
        else {
            painterCount++;
            // Did we run out of painters?
            if (painterCount > m) {
                return false; 
            }
            currentTime = boards[i]; // New painter starts with this board
        }
    }
    return true; // All boards successfully painted!
}

// ENGINE 2: The Binary Search -> O(log(sum - maxBoard))
int minTime(const vector<int> &boards, int n, int m) {
    int sum = 0;
    int maxBoard = 0;
    
    // Single-trip optimization: Find both worst-case (sum) and best-case (maxBoard)
    for (int i = 0; i < n; i++) {
        sum += boards[i];
        if (boards[i] > maxBoard) {
            maxBoard = boards[i];
        }
    }

    // Set the optimal boundaries
    int st = maxBoard, end = sum, ans = -1;
    
    while (st <= end) {
        int mid = st + (end - st) / 2;
        
        if (isValid(boards, n, m, mid)) {
            ans = mid;         // Limit works! Save it.
            end = mid - 1;     // Throw away right half to hunt for a tighter time limit.
        } else {
            st = mid + 1;      // Limit too strict! Throw away left half.
        }
    }
    return ans;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int n = boards.size();
    int m = 2; // 2 painters

    cout << "The minimum possible maximum time is: " << minTime(boards, n, m) << endl;
    
    return 0;
}