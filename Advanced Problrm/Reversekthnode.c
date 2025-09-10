#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void insertAtFront(Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

struct Node* reverseKGroup(Node* head, int k) {
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;

    int count = 0;

    struct Node* temp = head;

    for (int i = 0; i < k; i++) {
        if (temp == NULL)
            return head;
        temp = temp->next;
    }

    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
        head->next = reverseKGroup(next, k);
    if (head->next != NULL)
        head->next->prev = head;

    return prev;
}

int main() {
    Node* head = NULL;
    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 30);
    insertAtFront(&head, 40);
    insertAtFront(&head, 50);
    insertAtFront(&head, 60);

    printf("Original list:\n");
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    printf("Reversed in groups of %d:\n", k);
    printList(head);

    return 0;
}