// . Write a program to copy a linked list.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* createNode(int value)
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return NULL;
        }
        newNode->data = value;
        newNode->link = NULL;
        return newNode;    
    }

struct node* first = NULL;


 void insertAtFirst(int x) 
    {   
        struct node* newNode;
        newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }   
        newNode->data = x;
        newNode->link = first;
        first = newNode;
        
    }

    void printNode(struct  node*node)
    {
        if(node != NULL)
        {
            printf("Node data: %d\n", node->data);
        } 
        else
        {
            printf("Node is NULL\n");
        }
    };

    void copylist()
    {
        struct node* current = first;
        struct node* copyFirst = NULL;
        struct node* copyLast = NULL;
        while (current != NULL)
        {
            struct node* newNode = createNode(current->data);
            if (newNode == NULL)
            {
                return; 
            }
            if (copyFirst == NULL)
            {
                copyFirst = newNode;
            }
            else
            {
                copyLast->link = newNode;
            copyLast = newNode; 
            current = current->link; 
        }
    }
    void main()
    {
        insertAtFirst(10);
        insertAtFirst(20);
        insertAtFirst(30);
        insertAtFirst(40);
        insertAtFirst(50);
        printf("Original list:\n");
        struct node* current = first;
        while (current != NULL)
        {
            printNode(current);
            current = current->link;

        }
        printf("Copied list:\n");
        copylist();
        struct node* copyCurrent = first; 
        while (copyCurrent != NULL)
        {
            printNode(copyCurrent);
            copyCurrent = copyCurrent->link;
        }
        current = first;
        while (current != NULL)
        {
            struct node* temp = current;
            current = current->link;
            free(temp);
        }
        
    }
}