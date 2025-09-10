 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; 
void insertFront(int value);
void displayList();
void deleteFront();
void insertEnd(int value);
void deleteEnd();
void deleteAtPosition(int pos);
int countNodes();
void showMenu();

int main() {
    int choice, value, position;
    
    while(1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                displayList();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}

void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at front successfully.\n");
}

void displayList() {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteFront() {
    if(head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted successfully.\n");
}

void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if(head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at end successfully.\n");
}

void deleteEnd() {
    if(head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    if(head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    printf("Last node deleted successfully.\n");
}

void deleteAtPosition(int pos) {
    if(head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    if(pos == 1) {
        deleteFront();
        return;
    }
    
    struct Node* temp = head;
    for(int i = 1; temp != NULL && i < pos-1; i++) {
        temp = temp->next;
    }
    
    if(temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    printf("Node at position %d deleted successfully.\n", pos);
}


int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void showMenu() {
    printf("\n--- Singly Linked List Operations ---\n");
    printf("1. Insert at front\n");
    printf("2. Display all nodes\n");
    printf("3. Delete first node\n");
    printf("4. Insert at end\n");
    printf("5. Delete last node\n");
    printf("6. Delete from specified position\n");
    printf("7. Count nodes\n");
    printf("8. Exit\n");
}
