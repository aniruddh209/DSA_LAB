#include<stdio.h>
int main(){
    int m,n,sum=0;
    printf("Enter a range =");
        scanf("%d %d",&m,&n);
        for(int i=m;i<=n;i++){
            sum+=i;
        }
        printf("Sum was= %d",sum);
}