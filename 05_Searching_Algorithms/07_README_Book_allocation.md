# The Book Allocation Problem (Binary Search on Answers)

**The Core Paradigm Shift:**
Instead of using Binary Search to find an *index* in an array, we use it to guess the *mathematically perfect answer* from a number line of hypothetical possibilities. 

**The Goal:** Given an array of books (where each element is a page count) and `M` students, allocate the books so that the student with the heaviest backpack reads the **minimum possible maximum pages**.

### 1. Defining the Search Space
We must define the absolute lowest and highest possible page limits.
* **Best-Case Scenario (`st`):** `0` (or, strictly optimized, the single largest book in the array, because you cannot split a book in half).
* **Worst-Case Scenario (`end`):** The total sum of all books (happens if only 1 student has to read everything).
* **Fail-Safe (`ans`):** Initialized to `-1` in case the allocation is physically impossible (e.g., more students than books).

### 2. The `isValid()` Simulation (The Backpack Test)
For every `mid` value the Binary Search generates, we run a physical simulation to see if that strict page limit works.

**The 3 Rules of the Simulation:**
1. **The Impossible Book:** If a single book is larger than the `mid` limit, return `false`.
2. **The Backpack is Safe:** If adding the current book keeps the student's total <= `mid`, drop it in and move on.
3. **The Backpack is Full:** If adding the book exceeds the limit, stop. Bring in the next student and give the book to them. If the `studentCount` exceeds `M`, the limit is too strict—return `false`.

### 3. The C++ Engine

```cpp
#include <iostream>
#include <vector>
using namespace std;

// ENGINE 1: The Physical Simulation -> O(N)
bool isValid(const vector<int>& arr, int n, int m, int mid) {
    int studentCount = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        // Rule 1: A single book violates the limit
        if (arr[i] > mid) {
            return false;
        }

        // Rule 2: Book fits safely in current student's backpack
        if (currentPages + arr[i] <= mid) {
            currentPages += arr[i];
        } 
        // Rule 3: Backpack full, bring in next student
        else {
            studentCount++;
            if (studentCount > m) {
                return false; // Required too many students!
            }
            currentPages = arr[i]; // New student takes the current book
        }
    }
    return true; // Books successfully allocated!
}

// ENGINE 2: The Binary Search -> O(log(sum))
int allocateBooks(const vector<int> &arr, int n, int m) {
    // Edge case: More students than books
    if (m > n) return -1; 

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int st = 0, end = sum, ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) {
            ans = mid;        // Limit works! Save it.
            end = mid - 1;    // Throw away right half to hunt for a smaller limit.
        } 
        else {
            st = mid + 1;     // Limit too strict! Throw away left half.
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;
    cout << "Optimal Page Limit: " << allocateBooks(arr, n, m) << endl;
    return 0;
}
