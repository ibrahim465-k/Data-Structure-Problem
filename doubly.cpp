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
struct node *display_nth_node(struct node  *start,int nth){
    struct node *temp;
    temp=start;
    for (int i = 1; i < nth; i++)
    {
        temp=temp->next;
    }
    cout<<temp->data<<"\n";
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
    cout<<"\n which nth position you want to display: ";
    int nth;cin>>nth;
    start=display_nth_node(start,nth);
    return 0;
}