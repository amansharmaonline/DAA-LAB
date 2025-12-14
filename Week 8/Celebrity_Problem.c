#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of people: ");
    scanf("%d", &n);

    int k[n][n];

    printf("Enter the 'knows' matrix:\n");
    printf("For each person, enter %d numbers (1 if they know the person, 0 if not):\n", n);

    for (i = 0; i < n; i++) {
        printf("Person %d knows: ", i);
        for (j = 0; j < n; j++) {
            scanf("%d", &k[i][j]);
        }
    }

    int c = 0;
    int celeb = 1;

    for (i = 1; i < n; i++)
        if (k[c][i] == 1) c = i;

    for (i = 0; i < n; i++) {
        if (i == c) continue;
        if (k[c][i] == 1 || k[i][c] == 0) celeb = 0;
    }

    if (celeb)
        printf("Person %d is the celebrity.\n", c);
    else
        printf("No celebrity found.\n");

    return 0;
}
