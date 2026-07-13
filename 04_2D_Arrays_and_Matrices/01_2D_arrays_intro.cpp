#include <iostream>
using namespace std;

int diagonalSum(int matrix[][3], int n) {
    int totalSum = 0;

    // Strict O(N) Solution - Only ONE loop
    for (int i = 0; i < n; i++) {
        
        totalSum += matrix[i][i];

        totalSum += matrix[i][n - 1 - i];

    }

    return totalSum;
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Total Diagonal Sum: " << diagonalSum(matrix, 3) << endl;

    return 0;
}