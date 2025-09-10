
// #include<stdio.h>
// int main(){
//     int size,n,in,new;
//     int a[n];
//     printf("Enter sorted array element to delet=");
//     scanf("%d",&n);
//      printf("Enter a size of array=");
//     scanf("%d",&size);
//     printf("Enter a element=");
//     for(int i=0;i<size;i++){
//         scanf("%d",&a[i]);
//     }
//     for(int i=0;i<n;i++){
//         if(n==a[i]){
//             i=in;
//             break;
//         }
//     }
//         if(in<0 || in>n){
//             printf("not right that");
//         }
//         for(int i=in;i<size;i++){
//             a[i+1]=a[i];
//         }
//         printf("Now print Array=");
//         for(int i=0;i<n;i++){
//             printf("%d,",a[i]);
//         }

   

// }
#include<stdio.h>
int main(){
    int size, n, in = -1;
    
    printf("Enter size of array: ");
    scanf("%d", &size);
    int a[size];
    
    printf("Enter array elements:\n");
    for(int i = 0; i < size; i++){
        scanf("%d", &a[i]);
    }
    
    printf("Enter element to delete: ");
    scanf("%d", &n);
    
    for(int i = 0; i < size; i++){
        if(n == a[i]){
            in = i;
            break;
        }
    }
    
    if(in == -1){
        printf("Element not found in array.\n");
        return 1;
    }
    
    for(int i = in; i < size - 1; i++){
        a[i] = a[i + 1];
    }
    
    printf("Array after deletion:\n");
    for(int i = 0; i < size - 1; i++){ 
        printf("%d ", a[i]);
    }
    
    return 0;
}