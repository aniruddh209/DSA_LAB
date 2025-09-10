#include<stdio.h>
#define N 6
int deque[N];
int front = -1, rear = -1;

void insertFront(int value) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Deque Overflow");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = N - 1;
    }
    else {
        front--;
    }
    deque[front] = value;
    printf("Insert %d at front\n", value);
}

void insertRear(int value) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == N - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
    printf("Insert %d at rear", value);
}
void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Delete %d from front\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == N - 1) {
        front = 0;
    } else {
        front++;
    }
}
void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Delete %d from rear\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = N - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Element remaining was=");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % N;
    }
    printf("\n");
}

int main(){
    int Value;
    insertFront(10);
    insertFront(20);
    insertFront(20);
    insertRear(30);
    insertRear(40);
    deleteFront();
    deleteRear();
    deleteRear();
    display();
    
}