#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j, k;
    int g[10][10];

    printf("Number of vertices: ");
    scanf("%d", &n);

    printf("Adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i != j && g[i][j] == 0)
                g[i][j] = INT_MAX;

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (g[i][k] != INT_MAX && g[k][j] != INT_MAX &&
                    g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j];

    printf("All pair shortest paths:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (g[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%d ", g[i][j]);
        }
        printf("\n");
    }

    return 0;
}
