#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void display(float tp,int n,float res[]){
    printf("The items selected are: ");
    for(int i=0;i<n;i++){
        printf("%f ",res[i]);
    }
    printf("\nKnapsack profit: %f",tp);

}

float knapsack(int w[],int v[],int n,int W,float res[]){
    float tp=0.0,p[n];
    int max=INT_MIN,j;
    for(int i=0;i<n;i++){
        p[i]=(float)v[i]/w[i];
    }
    while(W>0){
        for(int i=0;i<n;i++){
            if(p[i]>max && res[i]!=1){
                max=p[i];
                j=i;
            }
        }
        max=INT_MIN;
        if(w[j]<=W){
            res[j]=1;
            W-=w[j];
            tp+=v[j];
        }
        else{
            res[j]=(float)W/w[j];
            tp+=res[j]*v[j];
            W=0;
        }
    }
    return tp;
}

int main(){
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int w[n],v[n];
    printf("Enter the profits and weights of the items: ");
    for(int i=0; i<n; i++){
        scanf("%d %d", &v[i],&w[i]);
    }
    int W;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    float res[n];
    for(int i=0;i<n;i++){
        res[i]=0.0;
    }
    float max=knapsack(w,v,n,W,res);
    display(max,n,res);
    
    return 0;
}