//3. Write and Implement the reverse traversal algorithm in the the linked list. Write main() to demonstrate the use of the function.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void insert(int val){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->next=head;
    head=new;
}

void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//reverse traversal using recursion
void reverse_print(struct node *temp){
    if(temp==NULL)
        return;
    reverse_print(temp->next);
    printf("%d ",temp->data);
}

int main(){
    int n,val,i;
    printf("enter no of nodes: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("enter value: ");
        scanf("%d",&val);
        insert(val);
    }
    
    printf("normal list: ");
    display();
    
    printf("reverse traversal: ");
    reverse_print(head);
    printf("\n");
    
    return 0;
}