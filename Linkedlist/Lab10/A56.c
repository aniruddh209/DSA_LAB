#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

int main() {
    
    struct Node* head = NULL; 
    head = (struct Node*)malloc(sizeof(struct Node));

    if (head == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter data for the node: ");
    scanf("%d", &head->data);
    head->next = NULL;        

    printf("\nNode Data: %d\n", head->data);
    printf("Next Node Address: %p\n", (void*)head->next);

    free(head);
    head = NULL; 

    return 0;
}