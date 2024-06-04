#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

void display(int tp,int res[],int maxdeadline){
    printf("Job profit: %d\n", tp);
    printf("Job sequence: ");
    for(int i=0;i<maxdeadline-1;i++){
        printf("J%d->",res[i]);
    }
    printf("J%d", res[maxdeadline-1]);
    printf("\n");
    
}

int job(int dea[],int pro[],int n,int maxdea,int res[]){
    int tp=0,vis[n],max=INT_MIN,j;
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    while(maxdea>0){
        for(int i=0;i<n;i++){
            if(pro[i]>max && vis[i]==0){
                max=pro[i];
                j=i;
            }
        }
        for(int i=dea[j]-1;i>=0;i--){
            if(res[i]==0){
                res[i]=j+1;
                tp+=pro[j];
                maxdea--;
                break;
            }
        }
        vis[j]=1;
        max=INT_MIN;
    }
    return tp;
}

int main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    int deadline[n], profit[n],maxdeadline=0;
    printf("Enter the deadline and profit: ");
    for(int i=0; i<n; i++){
        scanf("%d %d", &deadline[i], &profit[i]);
        if(deadline[i]>maxdeadline){
            maxdeadline=deadline[i];
        }
    }
    int res[maxdeadline];
    for(int i=0;i<maxdeadline;i++){
        res[i]=0;
    }
    int max=job(deadline,profit,n,maxdeadline,res);
    display(max,res,maxdeadline);
    return 0;
}