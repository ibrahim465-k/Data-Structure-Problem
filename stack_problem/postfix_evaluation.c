#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include<string.h>

// Stack node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push to stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop from stack
int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    int len =strlen(exp);
    for (int i = 0; i<len; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int a = pop();
            int b = pop();

            switch (ch) {
                case '+': push(b + a); break;
                case '-': push(b - a); break;
                case '*': push(b * a); break;
                case '/': push(b / a); break;
                case '^': push((int)pow(b, a)); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[100];
    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}
