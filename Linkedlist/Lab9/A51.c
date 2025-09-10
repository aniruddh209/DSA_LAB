#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int sum = 0;
    int* ptr = (int*)malloc(n * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed....");
        return 1;
    }
    
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr+i); //here &ptr[i]=ptr+i
    }
    
    for (int i = 0; i < n; i++) {
        sum += ptr[i];//=*(ptr+i)
    }
    
    printf("Sum of array elements: %d\n", sum);
    
    free(ptr);
    
    return 0;
}