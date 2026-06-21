#include <iostream>
#include <vector>
using namespace std;

bool isValid(const vector<int> &boards, int n, int m, int mid)
{
    int painterCount = 1;
    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        if (mid < boards[i])
        {
            return false;
        }
        if (currentTime + boards[i] <= mid)
        {
            currentTime += boards[i];
        }
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
    return true;
}

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
        if (isValid(boards, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
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
    int m = 2; // 2 painters

    cout << "The minimum possible maximum time is: " << minTime(boards, n, m) << endl;

    return 0;
}
