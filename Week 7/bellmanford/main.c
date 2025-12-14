
#include <stdio.h>
#include <limits.h>

struct Edge {
    int src, dest, weight;
};

void BellmanFord(int vertices, int edges, struct Edge edge[], int source) {
    int distance[vertices];

    // Initialize distances
    for (int i = 0; i < vertices; i++)
        distance[i] = INT_MAX;
    distance[source] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int w = edge[j].weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < edges; j++) {
        int u = edge[j].src;
        int v = edge[j].dest;
        int w = edge[j].weight;
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            printf("Graph contains a negative weight cycle!\n");
            return;
        }
    }

    // Print results
    printf("\n Shortest distances from source vertex %d:\n", source);
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INT_MAX)
            printf("Vertex %d : ∞\n", i);
        else
            printf("Vertex %d : %d\n", i, distance[i]);
    }
}

int main() {
    int vertices = 4;
    int edges = 5;

    
    struct Edge edge[] = {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -3},
        {2, 3, 4},
        {3, 1, 6}
    };

    int source = 0;
    BellmanFord(vertices, edges, edge, source);

    return 0;
}
