#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MaxVer 100
#define MaxEdge 100

typedef struct{
    int s,d,w;
}Edge;

void bellmanford(int v,int e,Edge *edge,int s)
{
    int dis[MaxVer],i,j;
    for(i=0;i<=v;i++)
    {
        dis[i]=INT_MAX;
    }
    dis[s]=0;
    for(i=0;i<v;i++)
    {
        for(j=0;j<e;j++)
        {
            if(dis[edge[j].s]!=INT_MAX && dis[edge[j].s]+edge[j].w<dis[edge[j].d])
            {
                dis[edge[j].d]=dis[edge[j].s]+edge[j].w;
            }
        }
    }
    for(i=0;i<e;i++)
    {
        if(dis[edge[i].s]!=INT_MAX && dis[edge[i].s]+edge[i].w<dis[edge[i].d])
        {
            printf("\nGraph contains negative weight cycle\n");
            return;
        }
    }
    printf("\nVertex\tDistance from source\n");
    for(i=0;i<v;i++)
    {
        printf("%d\t%d\n",i,dis[i]);
    }
}

int main()
{
    int ver,edg,i;
    printf("\nEnter the number of vertices and edges:\n");
    scanf("%d%d",&ver,&edg);
    Edge edge[MaxEdge];
    printf("\nEnter the source,destination and weight for each edge:\n");
    for(i=0;i<edg;i++)
    {
        scanf("%d%d%d",&edge[i].s,&edge[i].d,&edge[i].w);
    }
    bellmanford(ver,edg,edge,0);
}