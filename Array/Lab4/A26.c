#include<stdio.h>
int main(){
    int size, n, in = -1, new;
    
    printf("Enter size of array=");
    scanf("%d",&size);
    int a[size+1]; 
    
    printf("Enter sorted array elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    
    printf("Enter new element to insert=");
    scanf("%d",&new); 
    for(int i=0;i<size;i++){
        if(new < a[i]){
            in = i;
            break;
        }
    }
    if(in == -1){
        in = size;
    }
    for(int i=size;i>in;i--){
        a[i]=a[i-1];
    }
    a[in]=new;
    
    printf("New array after insert=\n");
    for(int i=0;i<size+1;i++){
        printf("%d\n",a[i]);
    }
    
    return 0;
}