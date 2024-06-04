#include<stdio.h>
#include<stdlib.h>
int board[20],count=0;
void display(int n){
    int i,j;
    printf("\n\nSolution:%d\n\n",++count);
    for(i=1;i<=n;i++){
        printf("\t%d",i);
    }
    for(i=1;i<=n;i++){
        printf("\n\n%d",i);
        for(j=1;j<=n;j++){
            if(board[i]==j){
                printf("\tQ");
            }
            else{
                printf("\t-");
            }
        }
    }
    printf("\n");
}

int place(int r,int c){
    for(int i=1;i<=r-1;i++){
        if(board[i]==c || abs(board[i]-c)==abs(i-r)){
            return 0;
        }
    }
    return 1;
}

void queen(int r,int n){
    for(int c=1;c<=n;c++){
        if(place(r,c)){
            board[r]=c;
            if(r==n){
                display(n);
            }
            else{
                queen(r+1,n);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of queens: ");
    scanf("%d",&n);
    queen(1,n);
    printf("Total solutions: %d\n",count);
    return 0;
}