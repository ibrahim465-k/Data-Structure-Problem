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
    cout<<"enter K-th Position "<<endl;
    cin>>a;
    if(a==1){
        
    }
    struct node *new_node,*ptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    cout<<endl;
   
   ptr=start;
    for(int i=1;i<a-1 && ptr!=NULL;i++){
    ptr=ptr->link;
   }
    cout<<"Enter new value of node"<<endl;
    cin>>new_node->data;
    new_node->link=ptr->link;
    ptr->link=new_node;
   cout<<"After add a node"<<endl;

    display_list(start);

}
