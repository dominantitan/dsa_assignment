//6. Given the array of the data (unsorted), Write a program to build the min and max heap.

#include<stdio.h>
#include<stdlib.h>

int heap[100];
int n;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void max_heapify(int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<n && heap[left]>heap[largest])
        largest=left;
    
    if(right<n && heap[right]>heap[largest])
        largest=right;
    
    if(largest!=i){
        swap(&heap[i],&heap[largest]);
        max_heapify(largest);
    }
}

void min_heapify(int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<n && heap[left]<heap[smallest])
        smallest=left;
    
    if(right<n && heap[right]<heap[smallest])
        smallest=right;
    
    if(smallest!=i){
        swap(&heap[i],&heap[smallest]);
        min_heapify(smallest);
    }
}

void build_max_heap(){
    int i;
    for(i=n/2-1;i>=0;i--)
        max_heapify(i);
}

void build_min_heap(){
    int i;
    for(i=n/2-1;i>=0;i--)
        min_heapify(i);
}

void display(){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
}

int main(){
    int i;
    
    printf("enter no of elements: ");
    scanf("%d",&n);
    
    printf("enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&heap[i]);
    
    printf("\noriginal array: ");
    display();
    
    build_max_heap();
    printf("max heap: ");
    display();
    
    //copy original array again for min heap
    printf("\nenter elements again for min heap: ");
    for(i=0;i<n;i++)
        scanf("%d",&heap[i]);
    
    build_min_heap();
    printf("min heap: ");
    display();
    
    return 0;
}