#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    struct Node* next;
};

struct Node* hashSet[SIZE];

// Hash function
int hash(int key) { return key % SIZE; }

// Add key
void add(int key) {
    int index = hash(key);
    struct Node* temp = hashSet[index];
    while(temp){
        if(temp->key==key){printf("%d already exists\n", key); return;}
        temp=temp->next;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key=key; newNode->next=hashSet[index];
    hashSet[index]=newNode;
    printf("%d added\n", key);
}

// Remove key
void removeKey(int key){
    int index=hash(key);
    struct Node* temp=hashSet[index], *prev=NULL;
    while(temp){
        if(temp->key==key){
            if(prev) prev->next=temp->next;
            else hashSet[index]=temp->next;
            free(temp);
            printf("%d removed\n",key);
            return;
        }
        prev=temp; temp=temp->next;
    }
    printf("%d not found\n", key);
}

// Contains key
int contains(int key){
    int index=hash(key);
    struct Node* temp=hashSet[index];
    while(temp){if(temp->key==key) return 1; temp=temp->next;}
    return 0;
}

// Display
void displaySet(){
    for(int i=0;i<SIZE;i++){
        printf("Bucket %d: ",i);
        struct Node* temp=hashSet[i];
        while(temp){printf("%d -> ", temp->key); temp=temp->next;}
        printf("NULL\n");
    }
}