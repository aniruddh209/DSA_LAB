
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    char branch[30];
    int batch_no;
};

int main() {
    // Allocate memory
    struct Student *ptr = (struct Student*)malloc(sizeof(struct Student));
    
    if(ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter student details:\n");
    
    printf("Roll Number: ");
    scanf("%d", &ptr->roll_no);
    
    printf("Name: ");
    scanf(" %[^\n]s", ptr->name);
    
    printf("Branch: ");
    scanf(" %[^\n]s", ptr->branch);
    
    printf("Batch Number: ");
    scanf("%d", &ptr->batch_no);
    
    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", ptr->roll_no);
    printf("Name: %s\n", ptr->name);
    printf("Branch: %s\n", ptr->branch);
    printf("Batch Number: %d\n", ptr->batch_no);
    
    free(ptr);
    
    return 0;
}