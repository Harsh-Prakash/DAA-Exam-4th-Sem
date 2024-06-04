#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int par[20]={0},mincost=0;

int find(int i)
{
    while(par[i])
        i=par[i];
    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        par[j]=i;
        return 1;
    }
    return 0;
}

void kruskal(int n,int cost[20][20])
{
    int i=1,j,a,b,u,v,min;
    printf("\nThe Edges of Minimum spanning tree are:\n");
    while(i<n)
    {
        min=INT_MAX;
        for(j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(cost[j][k]<min)
                {
                    min=cost[j][k];
                    a=u=j;
                    b=v=k;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("\n%d edge (%d,%d)cost =%d\n",i++,a,b,min);
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=INT_MAX;
    }
    printf("\nMinimum cost = %d\n",mincost);
}

int main()
{
    int n,cost[20][20];
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the cost matrix:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INT_MAX;
        }
    }
    kruskal(n,cost);
    return 0;
}