#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int rear= -1;
int front= -1;
void enqueue(int value){
    if(rear == SIZE-1){
        printf("overflow\n");
    }
    else if(front>rear || front== -1){
        front=rear=0;
        queue[rear]=value;
    }
    else {
        rear++;
        queue[rear]=value;
    }
}

void dequeue(){
    if(front==-1 || front>rear){
        printf("underflow\n");
    }
    else if(rear==front){
        printf("deleted value=%d\n",queue[front]);
        rear=front= -1;
    }
    else{
        printf("deleted value=%d\n",queue[front]);
        front++;
    }
}

void peek(){
    printf("peek value=%d\n",queue[front]);
}

void display(){
    if(rear== -1 && front== -1){
        printf("queue is empty");
    }
    else{
        for (int i = front; i <= rear; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main(){
   
    while (1)
    {
        printf("1.enqueue 2.dequeue 3.peek 4.display 5.exit\n");
        printf("give your choice");
       int choice;
        scanf("%d",&choice);
        switch(choice){
        case 1:{printf("give the value: ");
                int v;
                scanf("%d",&v);
                enqueue(v);
                break;} 
        case 2: dequeue();
                break;
        case 3: peek();
                break;
        case 4: display();
                break;
        case 5: return 0;
                break;
        default: printf("wrong choice");
    } 
    }
    
    

}