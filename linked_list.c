#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    struct node *start = NULL, *new_node, *ptr;
    int datum;

    printf("Enter -1 for ending the insertion of datum\n");
    printf("Enter the datum: ");
    scanf("%d", &datum);

    while (datum != -1) {
        // allocate memory for new node
        new_node = (struct node*) malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        new_node->data = datum;
        new_node->link = NULL;

        // first node
        if (start == NULL) {
            start = new_node;
        } 
        else {
            // traverse and add at the end
            ptr = start;
            while (ptr->link != NULL) {
                ptr = ptr->link;
            }
            ptr->link = new_node;
        }

        printf("Enter the datum: ");
        scanf("%d", &datum);
    }

    // Display the linked list
    printf("\nLinked List: ");
    ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    // Free memory
    ptr = start;
    while (ptr != NULL) {
        struct node* temp = ptr;
        ptr = ptr->link;
        free(temp);
    }

    return 0;
}