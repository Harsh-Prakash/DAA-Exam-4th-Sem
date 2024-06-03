#include<stdio.h>
#include<stdlib.h>

int partition(int arr[],int low,int high){
    int pivot = arr[low], d = low, u = high;
    while(d<u){
        while(arr[d]<=pivot){
            d++;
        }
        while(arr[u]>pivot){
            u--;
        }
        if(d<u){
            int temp=arr[d];
            arr[d]=arr[u];
            arr[u]=temp;
        }
    }
    arr[low]=arr[u];
    arr[u]=pivot;
    return u;
}


void quicksort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }

}


int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n-1);
    printf("Sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}