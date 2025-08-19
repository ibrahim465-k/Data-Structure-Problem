#include<stdio.h>
#define size 10
int queue[size];
int front=-1;
int rear=-1;
void enqueue(int value){
    if(front== -1 && rear== -1){
        front=rear= 0;
        queue[rear]=value;
    }
    else if((rear+1)%size == front){
        printf("queue is full\n");
    }
    else{
        rear=(rear+1)%size;
        queue[rear]=value;
    }
}
void dequeue(){
    if(front== -1 && rear== -1){
        printf("queue is empty\n");
    }
    else if(front == rear){
        printf("deleted value =%d\n",queue[front]);
        front=rear= -1;
    }
    else{
        printf("deleted value =%d\n",queue[front]);
        front=(front+1)%size;
    }
}
void peek(){
    printf("peek value =%d\n",queue[front]);
}
void display(){
    if(front== -1 && rear== -1){
        printf("queue is empty\n");
    }
    else{
        while (front!=rear)
        {
            printf("%d ",queue[front]);
            front=(front+1)%size;
        } 
        printf("%d",queue[front]);
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