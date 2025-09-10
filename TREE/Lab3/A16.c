#include<stdio.h>
int main(){
    int n;
    int a[n];
    printf("Enter The value you want in array=");
    printf("enter a length array=");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
    printf("%d",a[i]);
    }
}