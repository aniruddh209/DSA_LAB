#include <stdio.h>
#include <string.h>

int main() {
    char names[100][100], temp[100];
    int n, i, j;
    
    printf("Enter number of names: ");
    scanf("%d", &n);
    
    printf("Enter %d names:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    
    // Bubble sort for strings
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
    
    printf("Sorted names:\n");
    for(i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
    
    return 0;
}