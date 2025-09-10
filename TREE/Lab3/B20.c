#include <stdio.h>
int main() {
    int n;
    int a[100];
    printf("Enter total Element in array=");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter index %d element=\n",i);
        scanf("%d",&a[i]);
    }
    printf("Now print duplicate Number.........\n");
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                printf("Index of duplicate number was=%d\n",i);
                printf("Here is duplicate number=%d",a[i]);
                break;
            }
        }
    }
    return 0;
}