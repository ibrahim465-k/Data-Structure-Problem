#include<bits/stdc++.h>

using namespace std;

struct node{
    struct node *prev;
    int data;
    struct node *next;
    
};

struct node *start=NULL;
struct node *create_list(struct node *start){
    struct node *temp,*new_node;
    cout<<"enter -1 to stop insertion.\n";
    cout<<"give the data: ";
    int datum;cin>>datum;
    while(datum!=-1){
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=datum;
        //insertion at the end of the list.
         if(start==NULL){
        new_node->prev=NULL;
        
        new_node->next=NULL;
        start=new_node;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        new_node->prev=temp;
        temp->next=new_node;
        new_node->next=NULL;
    }
    cout<<"give the data: ";
    cin>>datum;
    }
   return start;
}
struct node *insertion_nth_node(struct node  *start,int nth,int whvalue){
    struct node *new_node,*temp;
    new_node=(struct node*)malloc(sizeof(struct node));
    temp=start;
    for (int i = 1; i < nth-1; i++)
    {
        temp=temp->next;
    }
    
    new_node->data=whvalue;
    new_node->next=temp->next;
    new_node->prev=temp;
    temp->next->prev=new_node;
    temp->next=new_node;

    return start;
}
void display_list(struct node *start)
{

    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    start=create_list(start);
    display_list(start);
    cout<<"\n which nth position you want to insert: ";
    int nth;cin>>nth;
    cout<<"\nwhich value you want to insert: ";
    int whvalue;cin>>whvalue;
    start=insertion_nth_node(start,nth,whvalue);
    display_list(start);
    return 0;
}