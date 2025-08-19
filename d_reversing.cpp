#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *prevs;
        struct node *link;
};
struct node *start;
struct node* inputlist(struct node *start){
    struct node *new_node;
    int data;
    printf("If you enter -1 then input will be stop.");
    printf("\nEnter Data for Node:");
    scanf("%d",&data);

    while(data!=-1){
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data= data;
        new_node->link=NULL;
        
        if(start==NULL){
            start=new_node;
        }else{
            struct node *ptr;
            ptr = start;
            while(ptr->link!=NULL){
                ptr=ptr->link;
            }
            ptr->link=new_node;
            new_node->prevs=ptr;
        }
        printf("Enter Data for Node:");
        scanf("%d",&data);
    }
    return start;
}
        void displaylist(struct node *start){

            struct node *ptr;

            ptr=start;
            while(ptr!=NULL){
                printf("%d ",ptr->data);
                ptr=ptr->link;
            }
            printf("\n");
 
        } 

        void revers(struct node *start){
            struct node *prevs,*next,*ptr;
            prevs=NULL;
            ptr=start;
            while(ptr!=NULL){
                next=ptr->link;
                ptr->link=prevs;
                prevs=ptr;
                ptr=next;
            }
            start=prevs;
            

            ptr=start;
            while(ptr!=NULL){
                printf("%d ",ptr->data);
                ptr=ptr->link;
            }

        }
    
        int main(){
            start=inputlist(start);
            displaylist(start);
            // between
            // printf("Enter data what you want to delete");
            // int data;
            // scanf("%d",&data);
            revers(start);
        

            return 0;
        }