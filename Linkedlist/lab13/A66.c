//sorted linkedlist
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* first = NULL;

void insertAtFirst(int x) {   
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }   
    newNode->data = x;
    newNode->next = first;
    first = newNode;
}

void printList(struct node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void sort() {
    struct node* current = first;
    struct node* nextindex = NULL;
    int temp;
    if (first == NULL) {
        return;
    }
    while (current != NULL) {
        nextindex = current->next;
        while (nextindex != NULL) {
            if (current->data > nextindex->data) {
                temp = current->data;
                current->data = nextindex->data;
                nextindex->data = temp;
            }
            nextindex = nextindex->next;
        }
        current = current->next;
    }
}

int main() {
    insertAtFirst(10);
    insertAtFirst(20);
    insertAtFirst(30);
    insertAtFirst(40);
    insertAtFirst(50);
    printf("Original list:\n");
    printList(first);

    sort();

    printf("Sorted list:\n");
    printList(first);

    return 0;
}