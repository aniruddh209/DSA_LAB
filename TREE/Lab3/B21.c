#include<stdio.h>
int main(){
    int m,n,c,count=0;
    printf("Enter length of the array= ");
    scanf("%d",&n);
     int a[n];
    for(int i=0;i<n;i++){
        printf("Enter a %d element=\n",i);
        scanf("%d",&a[i]);
    }
    printf("Enter 1st number m = \n");
    scanf("%d",&m);
    printf("Enter 2nd number c = \n");
    scanf("%d",&c);
    for(int i=0;i<n;i++){
        if(a[i]==m){
            a[i]=c;
            count++;
            break;
        }
    }
    if(count==0){
        printf("Not found..\n");
    }
    printf("Array was=\n");
    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }
}
         