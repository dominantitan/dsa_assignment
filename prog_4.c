//4. How can we implement the doubly linked list using structure? Write a method to insert(after given node) and delete the node in doubly linked list. Write main() to demonstrate the use of the functions.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;

void display(){
    struct node *temp=head;
    printf("list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert_at_end(int val){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    new->prev=NULL;
    
    if(head==NULL){
        head=new;
        return;
    }
    
    struct node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    
    temp->next=new;
    new->prev=temp;
}

//insert after given node
void insert_after(int after_val, int new_val){
    struct node *temp=head;
    
    while(temp!=NULL && temp->data!=after_val)
        temp=temp->next;
    
    if(temp==NULL){
        printf("node with value %d not found\n",after_val);
        return;
    }
    
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=new_val;
    new->next=temp->next;
    new->prev=temp;
    
    if(temp->next!=NULL)
        temp->next->prev=new;
    temp->next=new;
}

void delete_node(int val){
    struct node *temp=head;
    
    while(temp!=NULL && temp->data!=val)
        temp=temp->next;
    
    if(temp==NULL){
        printf("node with value %d not found\n",val);
        return;
    }
    
    if(temp->prev!=NULL)
        temp->prev->next=temp->next;
    else
        head=temp->next;
    
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    
    free(temp);
    printf("deleted %d\n",val);
}

int main(){
    int choice,val,after;
    
    while(1){
        printf("\n1.insert at end 2.insert after 3.delete 4.display 5.exit\n");
        printf("choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("enter value: ");
                scanf("%d",&val);
                insert_at_end(val);
                break;
            case 2:
                printf("insert after which value: ");
                scanf("%d",&after);
                printf("enter new value: ");
                scanf("%d",&val);
                insert_after(after,val);
                break;
            case 3:
                printf("delete which value: ");
                scanf("%d",&val);
                delete_node(val);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}