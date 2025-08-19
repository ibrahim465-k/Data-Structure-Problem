#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int value){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->link=NULL;
    if(front==NULL){
        rear=new_node;
        front=new_node;
        rear->link=front;
    }
    else{
        rear->link=new_node;
        rear=new_node;
        rear->link=front;
    }
}
void dequeue(){
    struct node *temp=front;
    if(front==NULL){
        printf("queue is empty\n");
    }
    else if(front==rear){
        printf("deleted value=%d\n",temp->data);
        front=rear= 0;
        free(temp);
    }
    else{
        printf("deleted value=%d\n",temp->data);
        front=front->link;
        rear->link=front;
        free(temp);
    }
}
void peek(){
    if(front==NULL){
        printf("queue is empty\n");
    }
    printf("peek value=%d\n",front->data);
}
void display(){
    struct node *temp=front;
    if(front==NULL){
        printf("queue is empty\n");
    }
    while(temp->link!=front){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("%d",temp->data);
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