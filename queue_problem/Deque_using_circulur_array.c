#include<stdio.h>
#define N 5
int deque[N];
int front= -1, rear= -1;
void enqueue_front(int value){
    if(front== -1 && rear== -1){
        front=rear= 0;
        deque[front]=value;
    }
    else if((rear+1)%N == front){
        printf("Deque is full\n");
    }
    else if(front== 0){
        front= N-1;
        deque[front]=value;
    }
    else{
        front--;
        deque[front]=value;
    }
}
void enqueue_rear(int value){
    if((rear+1)%N == front){
        printf("Deque is full\n");
    }
    else if(front== -1 && rear== -1){
        front=rear= 0;
        deque[rear]=value;
    }
    else if(rear == N-1){
    rear=(rear+1)%N;
    deque[rear]=value;
    }
    else{
        rear++;
        deque[rear]=value;
    }
}
void display(){
    int i=front;
    if(front== -1 && rear== -1){
        printf("deque is empty\n");
    }
    else{
        while ((i!=rear))
    {
        printf("%d ",deque[i]);
        i=(i+1)%N;
    }
    printf("%d",deque[i]);
    }
    printf("\n");
}
void getfront(){
    if(front== -1 && rear== -1){
        printf("deque is empty\n");
    }
    else{
        printf("front value is=%d\n",deque[front]);
    }  
}
void getrear(){
    if(front== -1 && rear== -1){
        printf("deque is empty\n");
    }
    else{
        printf("rear value is=%d\n",deque[rear]);
    }
}
void dequeue_front(){
    if(front== -1 && rear== -1){
        printf("deque is empty\n");
    }
    else if(front==rear){
        printf("deleted value=%d\n",deque[front]);
        front=rear= -1;
    }
    //front = (front + 1) % N;
    else if(front== N-1){
        printf("deleted value=%d\n",deque[front]);
        front=0;
    }
    else{
        printf("deleted value=%d\n",deque[front]);
        front++;
    }
}
void dequeue_rear(){
    if(front== -1 && rear== -1){
        printf("deque is empty\n");
    }
    else if(front==rear){
        printf("deleted value=%d\n",deque[rear]);
        front=rear= -1;
    }
    //rear = (rear - 1 + N) % N;
    else if(rear==0){
        printf("deleted value=%d\n",deque[rear]);
        rear=N-1;
    }
    else {
        printf("deleted value=%d\n",deque[rear]);
        rear--;
    }
}
int main(){
    while (1)
    {
        printf("1.enqueue_front 2.enqueue_rear 3.dequeue_front 4.dequeue_rear 5.getfront 6.getrear 7.display 8.exit\n");
        printf("enter your choice:");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:{
            printf("give the value:");
            int value;
            scanf("%d",&value);
            enqueue_front(value);
            break;
        }
        case 2:{
            printf("give the value:");
            int value;
            scanf("%d",&value);
            enqueue_rear(value);
            break;
        }
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            getfront();
            break;
        case 6:
            getrear();
            break;
        case 7:
            display();
            break;
        case 8:
            return 0;
            break;
        default:
            printf("wrong choice");
            break;
        }
    }
    
}