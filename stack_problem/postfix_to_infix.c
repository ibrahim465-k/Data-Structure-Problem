#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char data[100];
    struct node *link;
};

struct node *top = NULL;

// Push string to stack
void push(char *str) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->data, str);
    new_node->link = top;
    top = new_node;
}

// Pop and return top string
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

// Convert postfix to infix
void postfixToInfix(char *postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            // Make operand a string and push
            char operand[2] = {ch, '\0'};
            push(operand);
        } else if (isOperator(ch)) {
            // Pop two operands
            char *op1 = pop();
            char *op2 = pop();

            // Combine into infix expression
            char *expr = (char*)malloc(100 * sizeof(char));
            sprintf(expr, "(%s%c%s)", op2, ch, op1);
            push(expr);

            // Free temp operands
            free(op2);
            free(op1);
        }
    }

    // Final expression is on top
    char *result = pop();
    printf("Infix: %s\n", result);
    free(result);
}

int main() {
    char postfix[100];
    printf("Enter postfix expression (e.g. ab+c*): ");
    scanf("%s", postfix);

    postfixToInfix(postfix);
    return 0;
}
