#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Linked list node for stack
struct node {
    char data;
    struct node *link;
};
struct node *top = NULL;

// Push character to stack
void push(char ch) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = ch;
    new_node->link = top;
    top = new_node;
}

// Pop character from stack
char pop() {
    if (top == NULL) return '\0';
    struct node *temp = top;
    char val = temp->data;
    top = top->link;
    free(temp);
    return val;
}

// Peek top of stack
char peek() {
    if (top == NULL) return '\0';
    return top->data;
}

// Check if character is operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Get precedence of operator
int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

// Check if operator is right-associative
int isRightAssociative(char ch) {
    return (ch == '^');
}

// Reverse a string in-place
void reverse(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

// Swap '(' and ')' in a string
void swapBrackets(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
}

// Convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalpha(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != NULL && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        else if (isOperator(ch)) {
            while (top != NULL && peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                    (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // null-terminate
}

// Main function to convert infix to prefix
void infixToPrefix(char *infix, char *prefix) {
    char reversed[100], postfix[100];
    strcpy(reversed, infix);
    reverse(reversed);
    swapBrackets(reversed);
    infixToPostfix(reversed, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

// Driver code
int main() {
    char infix[100], prefix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);
    return 0;
}
