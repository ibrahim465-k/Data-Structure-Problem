#include<stdio.h>
#define size 50

int stack[size];
int top=-1;

void push(int n){
    if(top== size-1){
        printf("stack is full cannot push");
    }
    else{
        top++;
        stack[top]=n;
        printf("pushed hoise");
    }
}

void pop(){
    if(top==-1){
        printf("stack is empty so delete korbena");
    }
    else{
        printf("pop done");
        top--;
    }
}

void peek(){
    if(top== -1){
        printf("stack is empty");
    }
    else{
        printf("%d is top value\n",stack[top]);
    }
}

void display(){
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main(){
    while(1){
    printf("1.push,2.pop,3.peek,4.display,5.exit\n");
    int choice;scanf("%d",&choice);
    
    switch(choice){
        case 1:
            printf("give the value: ");
            int value;scanf("%d",&value);
            push(value);
            printf("\n");
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
            break;
        default:
            printf("invalid choice");
    }
    }
    return 0;
}