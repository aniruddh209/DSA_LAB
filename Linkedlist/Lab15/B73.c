#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void deleteAlternateNodes(struct Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        printf("List is empty or has only one node. Nothing to delete.\n");
        return;
    }

    struct Node* current = *head_ref;
    struct Node* temp;

    while (current != NULL && current->next != NULL) {
        temp = current->next;

        current->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = current;
        }

        free(temp);

        current = current->next;
    }

    printf("Alternate nodes deleted successfully.\n");
}

void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int i;
    for (i = 1; i <= 10; i++) {
        insertAtEnd(&head, i);
    }

    printf("Original list:\n");
    displayList(head);
    deleteAlternateNodes(&head);

    printf("List after deleting alternate nodes:\n");
    displayList(head);

    freeList(head);

    return 0;
}