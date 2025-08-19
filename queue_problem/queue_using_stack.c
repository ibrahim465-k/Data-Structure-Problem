#include<stdio.h>
#define N 5
int stack1[N],stack2[N];
int top1= -1 ,top2= -1;
int count=0;
void push1(int value){
    if(top1== N-1){
        printf("stack1 is full\n");
    }
    else{
        top1++;
        stack1[top1]=value;
    }
}
void push2(int value){
    if(top2== N-1){
        printf("stack1 is full\n");
    }
    else{
        top2++;
        stack2[top2]=value;
    }
}
int pop1(){
    int b= stack1[top1];
    top1--;
    return b;
}
int pop2(){
    int b= stack2[top2];
    top2--;
    return b;
}
void enqueue(int value){
    push1(value);
    count++;
}
void dequeue(){
    for (int i = 0; i < count; i++)
    {
        int a=pop1();
        push2(a);
    }
    int b=pop2();
    printf("dequeued value=%d\n",b);
    count--;
    for (int i = 0; i < count; i++)
    {
        int a=pop2();
        push1(a);
    }
}
void peek(){
    printf("peek value=%d\n",stack1[0]);
}
void display(){
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ",stack1[i]);
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