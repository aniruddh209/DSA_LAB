#include<stdio.h>

int recursiveBinary(a,left,right,key){
    int left=0;
    int right=n-1;

    if(left <= right){
        middle =(left+right)/2;
        
    }
    if(a[middle]== key){
        return middle;
    }
    else if(key<a[middle]){
        return recursiveBinary(a,left,middle-1,key);
    }
    else{
        return recursiveBinary(a,middle+1,right,key);
    }
    
} 

int main(){
    int n;
    int key;
    printf("enter size of array = ");
    scanf("%d",&n);
    printf("enter Sorted array !! \n");
    int a[n];
    for (int i = 0; i < n; i++) {
        printf("Enter %dth elements:\n", i);
        scanf("%d", &a[i]);
    }
        int left=0;
        int right=n-1;
    printf("Enter value to search: ");
    scanf("%d", &key);

recursiveBinary(a[n],left,right,key)  
  return 0;  
}