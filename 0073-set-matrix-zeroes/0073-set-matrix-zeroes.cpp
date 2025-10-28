class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool firstRow = false, firstCol = false;

    // Check if first row has zero
    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) firstRow = true;
    }

    // Check if first column has zero
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) firstCol = true;
    }

    // Use first row and column as markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set zeroes based on markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero first row if needed
    if (firstRow) {
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    // Zero first column if needed
    if (firstCol) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}

// Utility function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
};