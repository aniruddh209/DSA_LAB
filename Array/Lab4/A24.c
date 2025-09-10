#include<stdio.h>
int main(){
    int pos,n,in;
    int a[n];
        printf("Enter a element=");
        scanf("%d",&in);
        printf("Enter Size of array=");
        scanf("%d",&n);
        printf("Enter Array Element=");
        for(int i=0;i<n;i++){
            printf("Enter element no %d=",i);
            scanf("%d",&a[i]);
        }
        printf("Enter a remove element potion=");
        scanf("%d",&pos);
        if(pos<0 || pos>n){
            printf("not right that");
        }
        for(int i=n;i>pos;i--){
            a[i]=a[i-1];
        }
        a[pos]=in;
        printf("Now print Array=");
        for(int i=0;i<n;i++){
            printf("%d,",a[i]);
        }

}