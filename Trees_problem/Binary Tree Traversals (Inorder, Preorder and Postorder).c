#include <stdio.h>
#include <stdlib.h>

// Define a node structure for binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);   // Visit root
    preorder(root->left);        // Traverse left
    preorder(root->right);       // Traverse right
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);         // Traverse left
    printf("%d ", root->data);   // Visit root
    inorder(root->right);        // Traverse right
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);       // Traverse left
    postorder(root->right);      // Traverse right
    printf("%d ", root->data);   // Visit root
}

int main() {
    // Create tree nodes
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
