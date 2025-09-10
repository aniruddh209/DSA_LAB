#include<stdio.h>
int main(){
    int pos,n,del;
    int a[n];
        printf("Enter Size of array=");
        scanf("%d",&n);
        printf("Enter Array Element=");
        for(int i=0;i<n;i++){
            printf("Enter element no %d=",i);
            scanf("%d",&a[i]);
        }
        printf("Enter a  element position=");
        scanf("%d",&pos);
        if(pos<0 || pos>n){
            printf("not right that");
        }
        for(int i=pos;i<n;i++){
            a[i+1]=a[i];
        }
        printf("Now print Array=");
        for(int i=0;i<n-1;i++){
            printf("%d,",a[i]);
        }

}