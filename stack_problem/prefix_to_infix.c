#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack node
struct node {
    char data[100];           // expression string
    struct node *link;        // next node (linked list)
};

struct node *top = NULL;

// Push a string onto the stack
void push(char *str) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->data, str);
    new_node->link = top;
    top = new_node;
}

// Pop a string from the stack
char* pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct node *temp = top;
    char *str = (char*)malloc(100 * sizeof(char));
    strcpy(str, temp->data);
    top = top->link;
    free(temp);
    return str;
}

// Check if character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Convert prefix to infix
void prefixToInfix(char *prefix) {
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            // operand — wrap it in a string
            char operand[2] = {ch, '\0'};
            push(operand);
        } else if (isOperator(ch)) {
            // pop two operands
            char *op1 = pop();
            char *op2 = pop();

            // combine into infix: (op1 ch op2)
            char *expr = (char*)malloc(100 * sizeof(char));
            sprintf(expr, "(%s%c%s)", op1, ch, op2);
            push(expr);

            free(op1);
            free(op2);
        }
    }

    // Final expression
    char *result = pop();
    printf("Infix: %s\n", result);
    free(result);
}

int main() {
    char prefix[100];
    printf("Enter prefix expression (e.g. *+abc): ");
    scanf("%s", prefix);

    prefixToInfix(prefix);
    return 0;
}
