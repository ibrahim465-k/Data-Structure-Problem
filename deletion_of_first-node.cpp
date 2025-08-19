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
struct node *deletion_first_node(struct node *start){
     struct node *temp;
    temp=start;
    start=start->link;
    free(temp);
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
    cout<<"Original list:";
    display_list(start);
    start=deletion_first_node(start);
    cout<<"\n";
    cout<<"after deletion:";
    display_list(start);

}
