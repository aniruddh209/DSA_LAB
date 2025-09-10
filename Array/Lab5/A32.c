#include<stdio.h>
int main(){
    int a[3][2];
    int b[2][3];
    int c[3][3]={0};
    printf("Now enter a array=");
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
             printf("Enter a element=");
            scanf("%d",&a[i][j]);
        }
    }
    printf("Now enter a array b\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("Enter a element=");
            scanf("%d",&b[i][j]);
        }
    }
    printf("Now multiply this to array\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("Now print mulptiply matrix\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}