#include<stdio.h>
int main(){
    int n;
    int sum=0;
    printf("enter length of the array=");
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        sum+=i;
    }
    int avg=sum/n;
    printf("Avrage was %d",avg);
}