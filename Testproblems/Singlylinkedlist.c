#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert at position
void insertAtPosition(int data, int pos) {
    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Delete from position
void deleteFromPosition(int pos) {
    if (head == NULL || pos <= 0) {
        printf("Invalid position or empty list!\n");
        return;
    }
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

// Search an element
void searchElement(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list\n", key);
}

// Display the list
void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, pos, key;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search an Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &key);
                searchElement(key);
                break;
            case 8:
                displayList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}