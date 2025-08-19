#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create_node(){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: (give -1 for no node)");
    int x;scanf("%d",&x);
    if(x== -1){
        return 0;
    }
    new_node->data=x;
    printf("enter left child of %d",x);
    new_node->left=create_node();
    printf("enter right child of %d",x);
    new_node->right=create_node();
    return new_node;
}

void main(){
    struct node *root=NULL;
    root=create_node();
    
}