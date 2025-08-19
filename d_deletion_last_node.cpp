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
struct node *deletion_last_node(struct node *start){
    struct node *temp;
    temp=start;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
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
        temp=temp->next;
    }
}

int main(){
    start=create_list(start);
    cout<<"original list: ";
    display_list(start);
    start=deletion_last_node(start);
    cout<<"\nafter deletion: ";
    display_list(start);
    return 0;
}