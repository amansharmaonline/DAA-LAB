#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, u, v, min, total = 0, edges = 0;
    int a[10][10], vis[10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0)
                a[i][j] = INT_MAX;
        }
    }

    for(i = 0; i < n; i++)
        vis[i] = 0;

    vis[0] = 1;

    printf("\nEdges in MST:\n");

    while(edges < n - 1) {
        min = INT_MAX;
        for(i = 0; i < n; i++) {
            if(vis[i]) {
                for(j = 0; j < n; j++) {
                    if(!vis[j] && a[i][j] < min) {
                        min = a[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("%d - %d  weight = %d\n", u, v, min);
        vis[v] = 1;
        total += min;
        edges++;
    }

    printf("\nTotal weight = %d\n", total);
    return 0;
}
