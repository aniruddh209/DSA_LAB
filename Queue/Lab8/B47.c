#include<stdio.h>
#define N 5
int Queue[N];
int front = -1, rear = -1;

void insert(int value) {
    if ((front == 0 && rear == N - 1) || (rear + 1) % N == front) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % N;
    }
    Queue[rear] = value;
    printf("Inserted %d\n", value);
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted %d\n", Queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", Queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % N;
    }
    printf("\n");
}

int main() {
    insert(20);
    insert(10);
    insert(30);
    delete();
    display();
    return 0;
}