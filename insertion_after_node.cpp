#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *link;
};

struct node *start=NULL;

struct node* create_list(struct node *start) {
    struct node *new_node,*temp;
    int datum;
    cout<<"Enter -1 for ending the insertion of datum"<<endl;
    cout<<"Enter the datum:";
    cin>>datum;
    while(datum!=-1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=datum;
        new_node->link=NULL;

        if(start==NULL)   // first node
        {
            start=new_node;
        }
        else
        {
            temp=start;
            while(temp->link!=NULL)
                temp=temp->link;
            temp->link=new_node;  // link last node to new node
        }
        cout<<"Enter the datum:";
        cin>>datum;
    }
    return start;
}

void display_list(struct node *start) {
    struct node *temp=start;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}



int main() {
    start=create_list(start);
    cout<<"Original List: ";
    display_list(start);
    int a;
    struct node *temp,*ptr;
    cout<<endl;
   cout<<"Enter a value after this value add new node "<<endl;
   cin>>a;
   ptr=start;
   while(ptr!=NULL){
    if(ptr->data==a){
        break;
       }
       ptr=ptr->link;
    }
    cout<<"Enter new value of node"<<endl;
    cin>>temp->data;
    temp->link=ptr->link;
    ptr->link=temp;
   cout<<"After add a node"<<endl;
    ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }


}
