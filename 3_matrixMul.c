#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int matrixchain(int arr[], int n,int dp[n][n],int br[n][n]){
    for(int i=0; i<n; i++){
        dp[i][i]=0;
    }
    for(int l=2; l<n; l++){
        for(int i=1; i<n-l+1; i++){
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i; k<j; k++){
                int q=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(q<dp[i][j]){
                    dp[i][j]=q;
                    br[i][j]=k;
                }
            }
        }
    }
    return dp[1][n-1];
}

void brackets(int n,int br[n][n], int i, int j){
    if(i==j){
        printf("%c",65+i-1);
    }
    else{
        printf("(");
        brackets(n,br,i,br[i][j]);
        brackets(n,br,br[i][j]+1,j);
        printf(")");
    }
}

int main(){
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the dimensions of the matrices: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int dp[n][n],br[n][n];
    int min=matrixchain(arr,n,dp,br);
    printf("Cost Matrix: \n");
    for(int i=1; i<n; i++){
        for(int j=i; j<n; j++){
            printf("m[%d][%d] = %d\n",i,j,dp[i][j]);
        }
    }
    printf("Minimum number of multiplications: %d\n", min);
    brackets(n,br,1,n-1);
    return 0;
}