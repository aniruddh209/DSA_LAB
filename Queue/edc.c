#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct {
    int data;
    int priority;
} Element;

Element pq[MAX];
int size = 0; 
void insert(int data, int priority) {
    if (size == MAX) {
        printf("Queue Overflow!\n");
        return;
    }
    pq[size].data = data;
    pq[size].priority = priority;
    size++;
    printf("Inserted: %d with priority %d\n", data, priority);
}

void delete() {
    if (size == 0) {
        printf("Queue Underflow!\n");
        return;
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].priority > pq[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }

    printf("Deleted: %d with priority %d\n", pq[highestPriorityIndex].data, pq[highestPriorityIndex].priority);

    for (int i = highestPriorityIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void display() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Priority Queue elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Data: %d  Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    insert(10, 2);
    insert(20, 5);
    insert(30, 1);
    insert(40, 3);

    display();

    delete(); 
    display();

    delete(); 
    display();

    return 0;
}