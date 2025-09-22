#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
    printf("%d pushed\n", x);
}

// Pop
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped\n", stack[top--]);
}

// Peek
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element = %d\n", stack[top]);
}

// Display
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}