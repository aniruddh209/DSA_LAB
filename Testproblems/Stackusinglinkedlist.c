#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push
void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("%d pushed\n", x);
}

// Pop
void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped\n", temp->data);
    top = top->next;
    free(temp);
}

// Peek
void peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element = %d\n", top->data);
}

// Display
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Stack Menu ---\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &val); push(val); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}