#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 10

struct MapNode {
    int key;
    int value;
    struct MapNode* next;
};

struct MapNode* hashMap[MAP_SIZE];

// Hash function
int hashMapFunc(int key){ return key % MAP_SIZE; }

// Put (insert/update)
void put(int key, int value){
    int index=hashMapFunc(key);
    struct MapNode* temp=hashMap[index];
    while(temp){
        if(temp->key==key){temp->value=value; printf("Updated %d->%d\n",key,value); return;}
        temp=temp->next;
    }
    struct MapNode* newNode=(struct MapNode*)malloc(sizeof(struct MapNode));
    newNode->key=key; newNode->value=value;
    newNode->next=hashMap[index];
    hashMap[index]=newNode;
    printf("%d->%d added\n",key,value);
}

// Get value
int get(int key){
    int index=hashMapFunc(key);
    struct MapNode* temp=hashMap[index];
    while(temp){
        if(temp->key==key) return temp->value;
        temp=temp->next;
    }
    return -1; // Not found
}

// Remove key
void removeMap(int key){
    int index=hashMapFunc(key);
    struct MapNode* temp=hashMap[index]; struct MapNode* prev=NULL;
    while(temp){
        if(temp->key==key){
            if(prev) prev->next=temp->next;
            else hashMap[index]=temp->next;
            free(temp);
            printf("%d removed\n",key);
            return;
        }
        prev=temp; temp=temp->next;
    }
    printf("%d not found\n",key);
}

// Display map
void displayMap(){
    for(int i=0;i<MAP_SIZE;i++){
        printf("Bucket %d: ",i);
        struct MapNode* temp=hashMap[i];
        while(temp){printf("(%d->%d) ",temp->key,temp->value); temp=temp->next;}
        printf("NULL\n");
    }
}