#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return NULL;

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

int search(Node* root, int value) {
    if (root == NULL) return 0;
    if (root->value == value) return 1;

    if (value < root->value)
        return search(root->left, value);
    else
        return search(root->right, value);
}

void destroy_tree(Node* root) {
    if (root == NULL) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

void sort_tree(Node* root) {
    if (root == NULL) return;
    sort_tree(root->left);
    printf("%d ", root->value);
    sort_tree(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 7);

    printf("Отсортированное дерево: ");
    sort_tree(root);  // Должен напечатать: 5 7 10 15
    printf("\n");

    if (search(root, 7)) {
        printf("Значение найдено!\n");
    } else {
        printf("Значение не найдено.\n");
    }

    destroy_tree(root);
    return 0;
}