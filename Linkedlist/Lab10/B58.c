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

int areSame(struct Node* head1, struct Node* head2) {
    while (head1 && head2) {
        if (head1->data != head2->data)
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == NULL && head2 == NULL;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insertEnd(&list1, 1);
    insertEnd(&list1, 2);
    insertEnd(&list1, 3);

    insertEnd(&list2, 1);
    insertEnd(&list2, 2);
    insertEnd(&list2, 3);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    if (areSame(list1, list2))
        printf("Lists are SAME.\n");
    else
        printf("Lists are NOT SAME.\n");

    return 0;
}
