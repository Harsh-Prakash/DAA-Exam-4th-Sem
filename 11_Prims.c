#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int mincost = 0, vis[20] = {0};
void prim(int n, int cost[20][20])
{
    int i = 1, j, a, b, u, v, min;
    vis[1] = 1;
    printf("\nThe Edges of Minimum spanning tree are:\n");
    while (i < n)
    {
        min = INT_MAX;
        for (j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (cost[j][k] < min )
                {
                    if(vis[j]!=0)
                    {min = cost[j][k];
                    a = u = j;
                    b = v = k;}
                }
            }
        }
        if (vis[u] == 0 || vis[v] == 0)
        {
            printf("\n%d edge (%d,%d)cost =%d\n", i++, a, b, min);
            mincost += min;
            vis[b] = 1;
        }
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    printf("\nMinimum cost = %d\n", mincost);
}

int main()
{
    int n, cost[20][20];
    printf("\nEnter the number of nodes:");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    prim(n, cost);
    return 0;
}