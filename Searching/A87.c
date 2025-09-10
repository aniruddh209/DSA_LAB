#include<stdio.h>
int main(){
    int key,n;
    printf("Enter a element to find=");
    scanf("%d",&key);
    printf("Enter a size of array=");
    scanf("%d",&n);
    int a[n];
    printf("Enter lineaer array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(key==a[i]){
            printf("Find element at index %d\n",i);
        }
    }
}