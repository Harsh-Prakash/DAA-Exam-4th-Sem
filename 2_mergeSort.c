#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int low,int mid,int high){
    int n1=mid-low+1,n2=high-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[low+i];
    }
    for(int i=0;i<=n2;i++){
        b[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k++]=a[i++];
        }
        else{
            arr[k++]=b[j++];
        }
    }
    while(i<n1){
        arr[k++]=a[i++];
    }
    while(j<n2){
        arr[k++]=b[j++];
    }
}

void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
    mergesort(arr, 0, n-1);
    printf("Sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}