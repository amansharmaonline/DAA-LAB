#include <stdio.h>

// Function to rotate matrix 90° clockwise in place
void rotate90(int n, int a[n][n]) {
    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            int temp = a[i][l];
            a[i][l] = a[i][r];
            a[i][r] = temp;
        }
    }
}

// Utility to print matrix
void printMatrix(int n, int a[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    printMatrix(n, matrix);

    rotate90(n, matrix);

    printf("Matrix after 90° Clockwise Rotation:\n");
    printMatrix(n, matrix);

    return 0;
}
