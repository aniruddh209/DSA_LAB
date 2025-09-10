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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int isBalanced(struct Node* root) {
    if (root == NULL) return 1;  

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    struct Node* root1 = newNode(3);
    root1->left = newNode(9);
    root1->right = newNode(20);
    root1->right->left = newNode(15);
    root1->right->right = newNode(7);

    if (isBalanced(root1))
        printf("Output: TRUE\n");
    else
        printf("Output: FALSE\n");

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->left = newNode(3);
    root2->left->right = newNode(3);
    root2->left->left->left = newNode(4);
    root2->left->left->right = newNode(4);

    if (isBalanced(root2))
        printf("Output: TRUE\n");
    else
        printf("Output: FALSE\n");

    return 0;
}