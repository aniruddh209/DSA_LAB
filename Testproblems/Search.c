#include <stdio.h>

int linearSearchIter(int arr[], int n, int key) {
    for(int i=0;i<n;i++){
        if(arr[i]==key) return i; // Found at index i
    }
    return -1; // Not found
}

int main(){
    int arr[]={10,20,30,40,50};
    int n=5, key=30;
    int index=linearSearchIter(arr,n,key);
    if(index!=-1) printf("Found at index %d\n", index);
    else printf("Not found\n");
}
int binarySearchIter(int arr[], int n, int key) {
    int low=0, high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    return -1; // Not found
}

int main(){
    int arr[]={10,20,30,40,50};
    int n=5, key=20;
    int index=binarySearchIter(arr,n,key);
    if(index!=-1) printf("Found at index %d\n", index);
    else printf("Not found\n");
}
int binarySearchRec(int arr[], int low, int high, int key){
    if(low>high) return -1; // Not found
    int mid = low + (high-low)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]<key) return binarySearchRec(arr, mid+1, high, key);
    else return binarySearchRec(arr, low, mid-1, key);
}

int main(){
    int arr[]={10,20,30,40,50};
    int n=5, key=50;
    int index=binarySearchRec(arr,0,n-1,key);
    if(index!=-1) printf("Found at index %d\n", index);
    else printf("Not found\n");
}