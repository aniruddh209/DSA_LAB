#include<stdio.h>
struct node(
    int data;
    struct node *next;
    struct node *prev;
)
void insertAtFront(struct **ref_head,int new_data){
    struct node new_node=(struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = *ref_head;
    new_node->prev = NULL;

    if(*ref_head!=NULL){
        (*ref_head)->prev=new_node;
    }
    *ref_head=new_node;
}
void printevenorodd(struct node* head){
    while(head!=NULL){
    if(head%2==0){
        printf("even list this was");
        printf("%d->"head);
        head=head->next;
    }
    else if{
        printf("this was odd list");
        printf("%d->",head);
    }
    }
}
void printfList(struct node *node){
    while(node!=NULL){
        printf("%d -> ",new_node->x);
        node->next=node;
    }
}
int main(){
struct node* head=NULL;

insertAtFirst(&head,10);
insertAtFirst(&head,20);
insertAtFirst(&head,30);
insertAtFirst(&head,40);
printfList(head);
printevenorodd(head);

}