#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void swapKthNode(struct Node** head, int k) {
    int n = countNodes(*head);
    if (k > n) {
        printf("K is greater than the number of nodes.\n");
        return;
    }

    if (2 * k - 1 == n) {
        return;
    }

    struct Node *x = *head, *x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    struct Node *y = *head, *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    if (x_prev)
        x_prev->next = y;
    else
        *head = y;

    if (y_prev)
        y_prev->next = x;
    else
        *head = x;

    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
}

int main() {
    struct Node* head = NULL;

    // Create linked list: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Original Linked List:\n");
    printList(head);

    int k = 2;
    swapKthNode(&head, k);

    printf("\nLinked List after swapping %dth node from start and end:\n", k);
    printList(head);

    return 0;
}