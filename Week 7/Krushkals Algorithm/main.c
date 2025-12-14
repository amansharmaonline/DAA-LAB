#include <stdio.h>

int n, visited[10], graph[10][10];

int dfs(int u, int target) {
    visited[u] = 1;
    if(u == target) return 1;
    for(int v=0; v<n; v++)
        if(graph[u][v] && !visited[v])
            if(dfs(v,target)) return 1;
    return 0;
}

int main() {
    int e, edges[20][3], i, j, mst=0;

    printf("Vertices & edges: ");
    scanf("%d %d",&n,&e);

    printf("Edges (u v w):\n");
    for(i=0;i<e;i++) scanf("%d%d%d",&edges[i][0],&edges[i][1],&edges[i][2]);

    for(i=0;i<e-1;i++)
      for(j=0;j<e-i-1;j++)
        if(edges[j][2]>edges[j+1][2]){
            int t0=edges[j][0],t1=edges[j][1],t2=edges[j][2];
            edges[j][0]=edges[j+1][0]; edges[j][1]=edges[j+1][1]; edges[j][2]=edges[j+1][2];
            edges[j+1][0]=t0; edges[j+1][1]=t1; edges[j+1][2]=t2;
        }

    printf("MST edges:\n");
    for(i=0;i<e;i++){
        int u=edges[i][0],v=edges[i][1],w=edges[i][2];
        for(j=0;j<n;j++) visited[j]=0;
        if(!dfs(u,v)){
            graph[u][v]=graph[v][u]=w;
            printf("%d-%d : %d\n",u,v,w);
            mst+=w;
        }
    }

    printf("Total MST weight = %d\n",mst);
}
