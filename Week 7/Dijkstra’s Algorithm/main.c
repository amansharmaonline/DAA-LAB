#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j;
    int g[10][10], v[10], d[10];

    printf("Number of vertices: ");
    scanf("%d",&n);

    printf("Adjacency matrix (0 if no edge):\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&g[i][j]);

    for(i=0;i<n;i++){
        d[i]=INT_MAX;
        v[i]=0;
    }

    int s;
    printf("Start vertex: ");
    scanf("%d",&s);
    d[s]=0;

    for(i=0;i<n;i++){
        int min=INT_MAX,u=-1;
        for(j=0;j<n;j++)
            if(!v[j] && d[j]<min){
                min=d[j];
                u=j;
            }

        v[u]=1;

        for(j=0;j<n;j++)
            if(g[u][j] && !v[j] && d[u]+g[u][j]<d[j])
                d[j]=d[u]+g[u][j];
    }

    printf("Shortest distances from %d:\n",s);
    for(i=0;i<n;i++)
        if(d[i]==INT_MAX) printf("%d : INF\n",i);
        else printf("%d : %d\n",i,d[i]);

    return 0;
}
