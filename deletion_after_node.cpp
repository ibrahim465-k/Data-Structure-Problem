#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *start=NULL;

struct node* create_list(struct node *start)
{
    struct node *new_node,*temp;
    int datum;
    cout<<"Enter -1 for ending the insertion of datum"<<endl;
    cout<<"Enter the datum:";
    cin>>datum;
    while(datum!=-1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        if(start==NULL)
        {
            new_node->data=datum;
            new_node->link=NULL;
            start=new_node;
        }
        else
        {
            temp=start;
            while(temp->link!=NULL)
            temp=temp->link;
            //insertion after 
            new_node->data=datum;
            temp->link=new_node;
            new_node->link=NULL;
        }
        cout<<"Enter the datum:";
        cin>>datum;
    }
    return start;
}
struct node *deletion_after_node(struct node *start,int afvalue){
    struct node *temp,*next;
    temp=start;
    while(temp!=NULL){
        if(temp->data==afvalue){
            break;
        }
        temp=temp->link;
    }
    next=temp->link;
    temp->link=next->link;
    free(next);
    return start;
}
void display_list(struct node *start)
{

    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
}

int main()
{
    start=create_list(start);
    cout<<"original list: ";
    display_list(start);
    cout<<"\nafter which node you want to delete:";
    int afvalue;
    cin>>afvalue;
    
   start=deletion_after_node(start,afvalue);
    cout<<"\n";
    cout<<"after deltion:";
    display_list(start);

}
