#include<stdio.h>
int main(){
    int size;
    printf("Enter a size of an array=");
    scanf("%d",&size);
    int a[size][size];
    int b[size][size];
    int c[size][size];
    printf("Now enter a array a");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
             printf("Enter a element=");
            scanf("%d",&a[i][j]);
        }
    }
    printf("Now enter a array b\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("Enter a element=");
            scanf("%d",&b[i][j]);
        }
    }
    printf("Now add this two array\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            c[i][j]=a[i][j]+b[i][j];
            printf("%d\n",c[i][j]);
        }
    }
    
    }