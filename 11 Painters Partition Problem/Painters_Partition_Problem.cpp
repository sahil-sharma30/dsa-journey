#include <iostream>
#include <vector>
using namespace std;

// VALIDATION ENGINE: Checks if a proposed maximum time is physically possible for painters
bool isValid(const vector<int> &boards, int n, int m, int mid)
{
    int painterCount = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++)
    {
        // Edge Case: If a single board takes longer than the proposed max time
        if (mid < boards[i])
        {
            return false;
        }

        // If the current painter can take this board without breaching the time limit
        if (currentTime + boards[i] <= mid)
        {
            currentTime += boards[i];
        }
        // Deploy the next painter.
        else
        {
            painterCount++;
            
            if (painterCount > m)
            {
                return false;
            }
            
            currentTime = boards[i];
        }
    }
    return true; // The painters successfully painted all boards within the time limit
}

// BINARY SEARCH CONTROL UNIT: Finds the absolute minimum possible time
int minTime(const vector<int> &boards, int n, int m)
{
    int sum = 0;
    int maxBoard = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        if (boards[i] > maxBoard)
        {
            maxBoard = boards[i];
        }
    }

    int st = maxBoard, end = sum, ans = -1;
    
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        
        // If the proposed time is valid, record it as a potential answer.
        // Then, shrink the search space downward to see if we can do it even faster.
        if (isValid(boards, n, m, mid))
        {
            ans = mid;
            end = mid - 1; 
        }
        // If it's invalid, the time limit is physically impossible. Expand the search space upward.
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int n = boards.size();
    
    // Total painters available
    int m = 2; 

    cout << "The minimum possible maximum time is: " << minTime(boards, n, m) << endl;

    return 0;
}