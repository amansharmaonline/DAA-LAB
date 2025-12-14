#include <stdio.h>

int main()
{
    int A[10][10], B[10][10], C[10][10];
    int r1;
    int c1;
    int r2;
    int c2;

    printf("Enter the rows and columns for the matrix");
    scanf("%d", &r1);
    scanf("%d", &r2);
    scanf("%d", &c1);
    scanf("%d", &c2);

    if (c1 != r2) {
        printf("Not possible\n");
        return 0;
    }

    printf("Enter elements for matrix A\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements for matrix B\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Resultant Matrix C:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
