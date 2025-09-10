#include<stdio.h>
#define N 100

int queue[N];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == N - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1){
    front = 0;
    queue[++rear] = value;
    printf("Enqueued %d\n", value);
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        front = rear = -1;
        return;
    }
    printf("Dequeued %d\n", queue[front++]);
    if (front > rear) front = rear = -1;
}
int main(){
int value;
printf("Enter a value=");
scanf("%d",&value);
enqueue(value);
dequeue();
display();
}
