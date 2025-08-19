#include<iostream>
#include<malloc.h>
using namespace std;

struct node
{
    int datum;
    struct node* link;
};
struct node* start=NULL;

struct node* create_list(struct node* start)
{
    struct node* new_node/*, *ptr*/;

    int datum;
    cout<<"Enter -1 for stop pushing data"<<endl;

    cout<<"Enter datum in the link list: ";


    cin>>datum;


    while(datum!=-1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->datum=datum;
        new_node->link=NULL;
        if(start==NULL)
        {
            start=new_node;

        }
        else
        {
            struct node* ptr;
            ptr=start;
            while(ptr->link!=NULL)
                ptr=ptr->link;
            ptr->link=new_node;
            //new_node->link=NULL;
        }
        cout<<"Enter datum in the link list: ";
        cin>>datum;
    }
    return start;
};

void display_list(struct node* start)
{
    struct node* ptr;
    ptr=start;
    if(start==NULL)
    {
        cout<<endl<<"List is empty"<<endl;
        return;
    }
    else
    {
        while(ptr!=NULL)
        {
            cout<<ptr->datum<<" ";
            ptr=ptr->link;
        }
        cout<<endl;
    }


}

struct node* delete_first(struct node* start)
{
    struct node* temp,*ptr;
    ptr=start;
    while (ptr->link->link!=NULL)
    {
        ptr=ptr->link;
    }
    temp=ptr->link;
    ptr->link=temp->link;
    free(temp);

    return start;



};
int main()
{
    start=create_list(start);
    display_list(start);
    start=delete_first(start);
    cout<<"After deletion of the list"<<endl;
    display_list(start);
}
