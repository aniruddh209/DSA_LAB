#include <stdio.h>

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]) min_idx=j;
        }
        int temp=arr[i]; arr[i]=arr[min_idx]; arr[min_idx]=temp;
    }
}

void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j]; arr[j]=arr[j+1]; arr[j+1]=temp;
            }
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void displayArray(int arr[], int n){
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int arr[100], n, choice;

    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements: ", n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("\nArray before sorting: ");
    displayArray(arr,n);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n");
    printf("Enter choice: "); scanf("%d",&choice);

    switch(choice){
        case 1: selectionSort(arr,n); printf("Selection Sort Applied.\n"); break;
        case 2: bubbleSort(arr,n);    printf("Bubble Sort Applied.\n"); break;
        case 3: insertionSort(arr,n); printf("Insertion Sort Applied.\n"); break;
        default: printf("Invalid choice!\n"); return 0;
    }

    printf("Array after sorting: ");
    displayArray(arr,n);

    return 0;
}