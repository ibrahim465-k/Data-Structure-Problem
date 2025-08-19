#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *top=NULL;

void push(int value){
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->link=top;
    top=new_node;
}

void display(){
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    }
    printf("\n");
}

void peek(){
    if(top==NULL)printf("stack is empty");
    else{
        printf("top value is %d",top->data);
    }
    printf("\n");
}

void pop(){
    struct node *temp;
    temp=top;
    if(top==NULL)printf("stack is empty");
    else{
        printf("poped value:%d",temp->data);
        top=top->link;
        free(temp);
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