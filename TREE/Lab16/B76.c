#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;

    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root) {
    if (root == NULL)
        return 1;
    return isMirror(root->left, root->right);
}

int main() {
    struct Node* root1 = newNode(8);
    root1->left = newNode(5);
    root1->right = newNode(5);
    root1->left->left = newNode(3);
    root1->left->right = newNode(6);
    root1->right->left = newNode(6);
    root1->right->right = newNode(3);

    if (isSymmetric(root1))
        printf("Given tree is symmetric\n");
    else
        printf("Given tree is not symmetric\n");

    struct Node* root2 = newNode(8);
    root2->left = newNode(5);
    root2->right = newNode(7);
    root2->left->left = newNode(3);
    root2->left->right = newNode(6);
    root2->right->left = newNode(6);
    root2->right->right = newNode(3);

    if (isSymmetric(root2))
        printf("Given tree is symmetric\n");
    else
        printf("Given tree is not symmetric\n");

    return 0;
}