#include <stdio.h>

#define MAX 2
// Function to add two matrices
void addMatrix(int n, int a[][n], int b[][n], int c[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
}

// Function to subtract two matrices
void subMatrix(int n, int a[][n], int b[][n], int c[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] - b[i][j];
}

// Strassen’s recursive multiplication
void strassen(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
    int B11[k][k], B12[k][k], B21[k][k], B22[k][k];
    int C11[k][k], C12[k][k], C21[k][k], C22[k][k];
    int P[k][k], Q[k][k], R[k][k], S[k][k], T[k][k], U[k][k], V[k][k];
    int temp1[k][k], temp2[k][k];

    // Divide A and B into 4 submatrices each
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Strassen’s 7 products using your notation (P, Q, R, S, T, U, V)
    addMatrix(k, A11, A22, temp1);
    addMatrix(k, B11, B22, temp2);
    strassen(k, temp1, temp2, P);   // P = (A11 + A22) * (B11 + B22)

    addMatrix(k, A21, A22, temp1);
    strassen(k, temp1, B11, Q);     // Q = (A21 + A22) * B11

    subMatrix(k, B12, B22, temp2);
    strassen(k, A11, temp2, R);     // R = A11 * (B12 - B22)

    subMatrix(k, B21, B11, temp2);
    strassen(k, A22, temp2, S);     // S = A22 * (B21 - B11)

    addMatrix(k, A11, A12, temp1);
    strassen(k, temp1, B22, T);     // T = (A11 + A12) * B22

    subMatrix(k, A21, A11, temp1);
    addMatrix(k, B11, B12, temp2);
    strassen(k, temp1, temp2, U);   // U = (A21 - A11) * (B11 + B12)

    subMatrix(k, A12, A22, temp1);
    addMatrix(k, B21, B22, temp2);
    strassen(k, temp1, temp2, V);   // V = (A12 - A22) * (B21 + B22)

    // Compute C submatrices
    addMatrix(k, P, S, temp1);
    subMatrix(k, temp1, T, temp2);
    addMatrix(k, temp2, V, C11);    // C11 = P + S - T + V

    addMatrix(k, R, T, C12);        // C12 = R + T

    addMatrix(k, Q, S, C21);        // C21 = Q + S

    subMatrix(k, P, Q, temp1);
    addMatrix(k, temp1, R, temp2);
    addMatrix(k, temp2, U, C22);    // C22 = P - Q + R + U

    // Combine C11, C12, C21, C22 into C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX] = { {1, 2}, {3, 4} };
    int B[MAX][MAX] = { {5, 6}, {7, 8} };
    int C[MAX][MAX];

    strassen(MAX, A, B, C);

    printf("Resultant Matrix C:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}

