#include <stdio.h>

int knapsack(int W, int w[], int v[], int n) {
    if (n == 0 || W == 0)
        return 0;
    if (w[n-1] > W) {
        
        return knapsack(W, w, v, n-1);
    } else {
        
        int include = v[n-1] + knapsack(W - w[n-1], w, v, n-1);
        
        int exclude = knapsack(W, w, v, n-1);
    
        return (include > exclude) ? include : exclude;
    }
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int w[n], v[n];
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int maxValue = knapsack(W, w, v, n);
    printf("Maximum value possible: %d\n", maxValue);

    return 0;
}
