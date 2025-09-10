typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isMirror(Node* a, Node* b) {
    if (a == NULL && b == NULL) {
    return 1;
    }
    if (a == NULL || b == NULL) {
    return 0;
    }
    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

int isSymmetric(Node* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}
#include<stdio.h>
 int main(){
    

 }