#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int G[20][20],x[20];
void display(int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(x[i]>max){
            max=x[i];
        }
    }
    printf("Colors of vertices:\n");
    for(int i=0;i<n;i++){
        printf("Vertex[%d] = %d\n",i+1,x[i]);
    }
    printf("Minimum colors : %d",max);
}

void color(int n,int k){
    if(k==n){
        display(n);
        return;
    }
    x[k]=1;
    for(int i=0;i<n;i++){
        if(G[i][k]!=0 && x[i]==x[k]){
            x[k]=x[i]+1;
        }
    }
    color(n,k+1);
}

int main(){
    int v,e,k,l;
    printf("Enter no. of vertices and edges: ");
    scanf("%d%d",&v,&e);
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            G[i][j]=0;
    printf("Enter the edges:\n");
    for(int i=0;i<e;i++){
        scanf("%d%d",&k,&l);
        G[k][l]=G[l][k]=1;
    }
    color(v,0);
}