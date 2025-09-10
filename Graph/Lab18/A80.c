#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int findMin(struct Node* root) {
    struct Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current->key;
}

int findMax(struct Node* root) {
    struct Node* current = root;
    while (current->right != NULL)
        current = current->right;
    return current->key;
}

int main() {
    struct Node* root = NULL;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }
    printf("Smallest element: %d\n", findMin(root));
    printf("Largest element: %d\n", findMax(root));
    return 0;
}