#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int *ptr = (int*)malloc(n * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }
    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    
    free(ptr); 
    return 0;
}