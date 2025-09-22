#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Enqueue
void enqueue(int x) {
    if (isFull()) {
        printf("Circular Queue Overflow!\n");
        return;
    }
    if (front == -1) // first element
        front = 0;
    rear = (rear + 1) % MAX;
    cq[rear] = x;
    printf("%d enqueued\n", x);
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue Underflow!\n");
        return;
    }
    printf("%d dequeued\n", cq[front]);
    if (front == rear) { // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Peek
void peek() {
    if (isEmpty()) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Front element = %d\n", cq[front]);
}

// Display
void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
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