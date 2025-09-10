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

struct Node* buildTree(int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h)
        return NULL;

    struct Node* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (l == h || *preIndex >= size)
        return root;

    int i;
    for (i = l; i <= h; i++) {
        if (post[i] == pre[*preIndex])
            break;
    }

    if (i <= h) {
        root->left = buildTree(pre, post, preIndex, l, i, size);
        root->right = buildTree(pre, post, preIndex, i + 1, h - 1, size);
    }

    return root;
}

void printInorder(struct Node* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->key);
        printInorder(root->right);
    }
}

int main() {
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);
    int preIndex = 0;

    struct Node* root = buildTree(pre, post, &preIndex, 0, size - 1, size);

    printf("Inorder traversal of constructed tree:\n");
    printInorder(root);

    return 0;
}