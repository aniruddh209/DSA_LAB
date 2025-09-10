#include<stdio.h>
struct Node{
    int data;
    struct node* data;
}*Node;

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        printf("Inserted %d at the end of the list.\n", new_data);
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
    printf("Inserted %d at the end of the list.\n", new_data);
}
void displayList(){

}
int main(){
    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,40);
    insertAtEnd(&head,50);
    insertAtEnd(&head,60);
    insertAtEnd(&head,70);
    displayList(head);
}

