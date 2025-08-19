#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *last = NULL; // pointer to the last node

// ✅ Create list by inserting at the end
struct node* create_list(struct node *last) {
    struct node *new_node;
    int datum;
    printf("Enter -1 to stop insertion.\n");
    printf("Enter data: ");
    scanf("%d", &datum);

    while (datum != -1) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = datum;

        if (last == NULL) {
            // first node in circular list
            last = new_node;
            last->next = last; // points to itself
        } else {
            new_node->next = last->next; // new node points to head
            last->next = new_node;       // old last points to new node
            last = new_node;             // update last
            //to create list insertion at the begining
            // new_node->next = last->next;  
            // last->next = new_node;  
        }
        printf("Enter data: ");
        scanf("%d", &datum);
    }
    return last;
}

// ✅ Display circular linked list
void display(struct node *last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = last->next; // head node
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

// ✅ Insert node at the end
struct node* insert_end(struct node *last, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;

    if (last == NULL) {
        last = new_node;
        last->next = last;
    } else {
        new_node->next = last->next;
        last->next = new_node;
        last = new_node;
    }
    return last;
}


// ✅ Insert at the beginning of circular linked list
struct node* insert_beginning(struct node *last, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;

    if (last == NULL) {
        // If the list is empty
        last = new_node;
        last->next = last;  // Points to itself
    } else {
        new_node->next = last->next;  // New node points to head
        last->next = new_node;        // Last node now points to new node
    }

    return last;
}

// ✅ Insertion after a node of circular linked list
struct node *after_node(struct node *last,int afvalue,int whvalue){
    struct node *new_node,*temp=last->next;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=whvalue;
    do{
        if(temp->data==afvalue)
        break;
        temp=temp->next;
    }while (temp!=last->next);
    new_node->next=temp->next;
    temp->next=new_node;

    return last;
}

// ✅ Insertion before a node of circular linked list
struct node *before_node(struct node *last,int befvalue,int whvalue){
    struct node *new_node,*temp=last->next;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=whvalue;
    do{
        if(temp->next->data==befvalue)
        break;
        temp=temp->next;
    }while (temp!=last->next);
    new_node->next=temp->next;
    temp->next=new_node;

    return last;
}

// ✅ Insertion in nth node of circular linked list
struct node *nth_node(struct node *last,int nth,int whvalue){
    struct node *new_node,*temp=last->next;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=whvalue;
    for (int i = 1; i < nth-1; i++)
    {
        temp=temp->next;
    }
    
    new_node->next=temp->next;
    temp->next=new_node;

    return last;
}

// ✅ Delete the first node 
struct node* delete_first(struct node *last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct node *temp = last->next;

    // Only one node in list
    if (last == temp) {
        free(temp);
        return NULL;
    }

    last->next = temp->next;
    free(temp);
    return last;
}


// ✅ Delete the last node in the circular linked list
struct node* delete_last(struct node *last) {
    struct node *temp = last->next; 

    while (temp->next != last) {  // Find the node before last
        temp = temp->next;
    }

    temp->next = last->next;  // The new last should point to head
    free(last);
    last = temp;              // Update last

    return last;
}

// ✅ Delete before a node in the circular linked list
struct node* delete_before_node(struct node *last,int before) {
    struct node *temp = last->next,*delete; 

    do{
        if(temp->next->next->data==before)
        break;
        temp=temp->next;
    }while (temp!=last->next);
    delete=temp->next;
    temp->next=delete->next;
    free(delete);

    return last;
}

int main() {
    int choice, value;
    while (1) {
        printf("\n---- Circular Linked List Menu ----\n");
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Insert at End\n");
        printf("4. Insert at the beginning\n");
        printf("5. Insertion after a node\n");
        printf("6. Insertion before a node\n");
        printf("7. Insertion in nth  node\n");
        printf("8. Delete the first node\n");
        printf("9. Delete the last node\n");
        printf("10. Delete before a node\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                last = create_list(last);
                break;
            case 2:
                display(last);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                last = insert_end(last, value);
                break;
            case 4:
                printf("which value you want to insert: ");
                scanf("%d", &value);
                last = insert_beginning(last,value);
                break;
            case 5:
                printf("after which value you want to insert: ");
                int afvalue;scanf("%d",&afvalue);
                printf("which value you want to insert: ");
                int whvalue;scanf("%d",&whvalue);
                last=after_node(last,afvalue,whvalue);
                break;
            case 6:
                printf("before which value you want to insert: ");
                int befvalue;scanf("%d",&befvalue);
                printf("which value you want to insert: ");
                int wvalue;scanf("%d",&wvalue);
                last=before_node(last,befvalue,wvalue);
                break;
            case 7:
                printf(" which nth node you want to insert: ");
                int nth;scanf("%d",&nth);
                printf("which value you want to insert: ");
                int value;scanf("%d",&value);
                last=nth_node(last,nth,value);
                break;
            case 8:
                last=delete_first(last);
                break;
            case 9:
                last=delete_last(last);
                break;
            case 10:
            printf("before which value you want to delete");
                int before;scanf("%d",&before);
                last=delete_before_node(last,before);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
