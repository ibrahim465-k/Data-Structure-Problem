//one level after one level from left to right.
//how can i know parent child relation
#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // maximum size of the tree array

// Tree stored as array
int tree[MAX];

// Initialize tree with -1 (empty)
void initTree() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }
}

// Insert value at root
void setRoot(int value) {
    if (tree[0] != -1) {
        printf("Root already exists!\n");
    } else {
        tree[0] = value;
    }
}

// Insert left child
void setLeft(int parentIndex, int value) {
    int leftIndex = 2 * parentIndex + 1;
    if (tree[parentIndex] == -1) {
        printf("Cannot set left child at index %d, no parent!\n", parentIndex);
    } else if (leftIndex >= MAX) {
        printf("Index out of range!\n");
    } else {
        tree[leftIndex] = value;
    }
}

// Insert right child
void setRight(int parentIndex, int value) {
    int rightIndex = 2 * parentIndex + 2;
    if (tree[parentIndex] == -1) {
        printf("Cannot set right child at index %d, no parent!\n", parentIndex);
    } else if (rightIndex >= MAX) {
        printf("Index out of range!\n");
    } else {
        tree[rightIndex] = value;
    }
}

// Print tree (array representation)
void printTree() {
    printf("Tree array:\n");
    for (int i = 0; i < MAX; i++) {
        if (tree[i] != -1) {
            printf("Index %d -> %d\n", i, tree[i]);
        }
    }
}

int main() {
    initTree();

    setRoot(1);              // Root
    setLeft(0, 2);           // Left child of root
    setRight(0, 3);          // Right child of root
    setLeft(1, 4);           // Left child of node 2
    setRight(1, 5);          // Right child of node 2

    printTree();

    return 0;
}
