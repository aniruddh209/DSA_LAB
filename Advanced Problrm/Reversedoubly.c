#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} *head = NULL, *last = NULL;

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        last = new_node;
        printf("Inserted %d at the end of the list.\n", new_data);
        return;
    }
    new_node->prev = last;
    last->next = new_node;
    last = new_node; 
    printf("Inserted %d at the end of the list.\n", new_data);
}
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (node != NULL) {
        printf("%d<->", node->data);
        node = node->next;
    }
    printf("\n");
}
void reverselist() {
    if (head == NULL)
    return;
    
    struct Node *current = head, *temp = NULL;
    while (current != NULL) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    temp = head;
    head = last;
    last = temp;
}
int main() {
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);
    insertAtEnd(&head, 70);
    displayList(head);
    reverselist();
    printf("After reversing:\n");
    displayList(head);
    return 0;
}