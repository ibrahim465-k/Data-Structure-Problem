#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    char data;
    struct Node* next;
};

// Stack top pointer
struct Node* top = NULL;

// Push onto stack
void push(char ch) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

// Pop from stack
char pop() {
    if (top == NULL)
        {
            printf("stack is empty");//return '\0';
        }
    char val = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return val;
}

// Peek at top of stack
char peek() {
    if (top == NULL)
        return '\0';//printf("stack is empty");
    return top->data;
}

// Check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Return precedence of operator
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Check right-associativity
int isRightAssociative(char op) {
    return op == '^';
}

// Infix to postfix conversion
void infixToPostfix(char* infix) {
    char postfix[100];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If alphabet , add to output
        if (isalpha(ch)) {//isalpha()->alphabet kina tar function.
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (top != NULL && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }
        // If operator
        else if (isOperator(ch)) {
            while (top != NULL && peek() != '(' &&
                  (precedence(peek()) > precedence(ch) ||
                  (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop any remaining operators
    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null terminate

    printf("Postfix Expression: %s\n", postfix);
}

// Main function
int main() {
    char infix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
