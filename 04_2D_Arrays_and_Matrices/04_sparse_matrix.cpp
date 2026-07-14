#include <iostream>
using namespace std;

void convertToSparse() {
    // A 4x5 grid where almost everything is 0
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    // Step 1: Count how many non-zero numbers actually exist
    int nonZeroCount = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    // Step 2: Create the compressed Triplet Matrix
    // It always has 3 rows (Row, Col, Value) and 'nonZeroCount' columns
    int sparseMatrix[3][nonZeroCount];

    // Step 3: Extract the non-zero values and their coordinates
    int k = 0; // Tracks the column in our new compressed matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[0][k] = i;            // Store the Row index
                sparseMatrix[1][k] = j;            // Store the Column index
                sparseMatrix[2][k] = matrix[i][j]; // Store the Actual Value
                k++;
            }
        }
    }

    // Step 4: Display the compressed result
    cout << "--- Compressed Sparse Matrix ---" << endl;
    cout << "Row\tCol\tValue" << endl;
    for (int i = 0; i < nonZeroCount; i++) {
        cout << sparseMatrix[0][i] << "\t" 
             << sparseMatrix[1][i] << "\t" 
             << sparseMatrix[2][i] << endl;
    }
}

int main() {
    convertToSparse();
    return 0;
}