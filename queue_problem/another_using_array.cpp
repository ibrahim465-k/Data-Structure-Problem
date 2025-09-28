#include<iostream>
#define MAX 50
using namespace std;

int queue[MAX],front,rear;

void initialize()
{
    front=-1;
    rear=-1;
}
void insert(int value)
{
    if(rear==(MAX-1))
    {
        cout<<"Queue is overflow"<<endl;
        return;
    }

    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        queue[rear]=value;
    }
    else
    {
        rear++;
        queue[rear]=value;

    }
}

void display()
{
    if(front>rear || front==-1 )
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    else
    {
        for(int i=front; i<=rear; i++)
        {
            cout<<"Element of Queue is :"<<queue[i]<<endl;
        }
    }
}

void delete_queue()
{
    if(front>rear || front==-1 )
    {
        cout<<"Queue is Empty"<<endl;

        return;
    }

    else
    {
        cout<<"Deleted element is : "<<queue[front]<<endl;
        // queue[front]=-1;

        front++;
        if(front>rear)
        {
            front=rear=-1;
            return;
        }
    }
}
int main()
{
    initialize();
    cout<<"Enter 1 for insert"<<endl;
    cout<<"Enter 2 for delete"<<endl;
    cout<<"Enter 3 for display"<<endl;

    int val;
    cout<<endl<<"Enter for inser/delete/display: ";
    cin>>val;

    cout<<"----------------------"<<endl;

    while(val!=0)
    {
        if(val==1)
        {
            int x;
            cout<<"Enter -1 to stop entering in the Queue"<<endl;
            cout<<"Enter element in the queue: ";
            cin>>x;
            while(x!=-1)
            {
                insert(x);
                cout<<"Enter element in the queue: ";
                cin>>x;
            }
        }

        if(val==2)
        {
            delete_queue();
        }
        if(val==3)
        {
            display();
        }
        cout<<endl;
        cout<<"Enter 1 for insert"<<endl;
        cout<<"Enter 2 for delete"<<endl;
        cout<<"Enter 3 for display"<<endl;
        cout<<"Enter for insert/delete/display: ";
        cin>>val;
        cout<<"---------------------"<<endl;
    }

//            cout<<"Enter -1 to stop entering in the Queue"<<endl;
//            cout<<"Enter element in the queue: ";
//            int x;
//            cin>>x;
//            while(x!=-1)
//            {
//                insert(x);
//                cout<<"Enter element in the queue: ";
//                cin>>x;
//            }
//            display();
    return 0;

}
