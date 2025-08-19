#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->link = NULL;

    if (front == NULL) { // queue empty
        front = rear = new_node;
    } else {
        rear->link = new_node; // connect old last to new node
        rear = new_node;       // update rear
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    }
    struct node *temp = front;
    printf("Deleted value = %d\n", front->data);

    if (front == rear) { // only one element
        front = rear = NULL;
    } else {
        front = front->link;
    }
    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Peek value = %d\n", front->data);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    while (1) {
        printf("1.Enqueue  2.Dequeue  3.Peek  4.Display  5.Exit\n");
        printf("Give your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Give the value: ");
                int v;
                scanf("%d", &v);
                enqueue(v);
                break;
            }
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Wrong choice\n");
        }
    }
}
