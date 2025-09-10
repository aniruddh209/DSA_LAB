#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeDuplicates(struct Node* head) {
    struct Node *current = head, *temp, *dup;
    
    while (current != NULL && current->next != NULL) {
        temp = current;
        while (temp->next != NULL) {
            if (current->data == temp->next->data) {
                dup = temp->next;
                temp->next = temp->next->next;
                free(dup);
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;
    
    push(&head, 10);
    push(&head, 20);
    push(&head, 10);
    push(&head, 30);
    push(&head, 20);
    
    printf("Original List: ");
    printList(head);
    
    removeDuplicates(head);
    
    printf("List after removing duplicates: ");
    printList(head);
    
    return 0;
}