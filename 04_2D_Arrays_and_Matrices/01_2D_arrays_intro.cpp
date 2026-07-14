#include <iostream>
#include <climits>
using namespace std;

int maxRowSum(int matrix[][3], int rows, int cols)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        int currentSum = 0;
        for (int j = 0; j < cols; j++)
        {
            currentSum += matrix[i][j];
        }
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }
    return maxSum;
}

int diagonalSum(int matrix[][3], int n)
{
    int totalSum = 0;

    // Strict O(N) Solution - Only ONE loop
    for (int i = 0; i < n; i++)
    {
        // Primary Diagonal (Top-Left to Bottom-Right)
        totalSum += matrix[i][i];

        // Secondary Diagonal (Top-Right to Bottom-Left)
        totalSum += matrix[i][n - 1 - i];

        // Subtract the duplicate
        if (i == n - 1 - i)
        {
            totalSum -= matrix[i][i];
        }
    }

    return totalSum;
}

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Total Diagonal Sum: " << diagonalSum(matrix, 3) << endl;
    cout << "Maximum Row Sum: " << maxRowSum(matrix, 3, 3) << endl;

    return 0;
}