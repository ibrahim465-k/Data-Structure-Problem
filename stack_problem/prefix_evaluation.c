#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL;

void push(int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->link = top;
    top = new_node;
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct node *temp = top;
    int value = top->data;
    top = top->link;
    free(temp);
    return value;
}

int evaluate_prefix(char *prefix) {
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to int
        }
        else {
            int a = pop();
            int b = pop();
            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': push((int)pow(a, b)); break;
            }
        }
    }
    return pop();
}

int main() {
    char prefix[100];
    printf("Enter prefix expression (no spaces, single digits only): ");
    scanf("%s", prefix);

    int result = evaluate_prefix(prefix);
    printf("Result = %d\n", result);
    return 0;
}
