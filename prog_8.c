// 8. Write a program that generates a list of N random integers in the range [1, 1000], where N
// is provided by the user at run time. Then, perform the following tasks:
// (a) Ask the user to choose a sorting algorithm from the following:
// • Bubble Sort
// • Selection Sort
// • Insertion Sort
// • Merge Sort
// (b) Sort the randomly generated numbers using the chosen algorithm.
// (c) Print the numbers before and after sorting.
// (d) Display the total number of comparisons and swaps (if applicable) performed by the
// chosen algorithm.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int arr[1000];
int temp[1000];
int n;
int comparisons=0;
int swaps=0;

void generate_random(){
    int i;
    srand(time(0));
    for(i=0;i<n;i++)
        arr[i]=rand()%1000+1;
}

void display(){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void bubble_sort(){
    int i,j;
    comparisons=0;
    swaps=0;
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            comparisons++;
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swaps++;
            }
        }
    }
}

void selection_sort(){
    int i,j,min_idx;
    comparisons=0;
    swaps=0;
    
    for(i=0;i<n-1;i++){
        min_idx=i;
        for(j=i+1;j<n;j++){
            comparisons++;
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        if(min_idx!=i){
            int temp=arr[i];
            arr[i]=arr[min_idx];
            arr[min_idx]=temp;
            swaps++;
        }
    }
}

void insertion_sort(){
    int i,j,key;
    comparisons=0;
    swaps=0;
    
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0){
            comparisons++;
            if(arr[j]>key){
                arr[j+1]=arr[j];
                swaps++;
                j--;
            }
            else break;
        }
        arr[j+1]=key;
    }
}

void merge(int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    
    int L[500],R[500];
    
    for(i=0;i<n1;i++)
        L[i]=arr[left+i];
    for(j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
    
    i=0;j=0;k=left;
    
    while(i<n1 && j<n2){
        comparisons++;
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1){
        arr[k]=L[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;k++;
    }
}

void merge_sort(int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        merge_sort(left,mid);
        merge_sort(mid+1,right);
        merge(left,mid,right);
    }
}

void copy_array(){
    int i;
    for(i=0;i<n;i++)
        temp[i]=arr[i];
}

void restore_array(){
    int i;
    for(i=0;i<n;i++)
        arr[i]=temp[i];
}

int main(){
    int choice;
    
    printf("enter number of elements (max 1000): ");
    scanf("%d",&n);
    
    generate_random();
    copy_array();
    
    printf("\noriginal array: ");
    display();
    
    printf("\nchoose sorting algorithm:\n");
    printf("1. bubble sort\n");
    printf("2. selection sort\n");
    printf("3. insertion sort\n");
    printf("4. merge sort\n");
    printf("choice: ");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:
            printf("\nusing bubble sort...\n");
            bubble_sort();
            printf("comparisons: %d, swaps: %d\n",comparisons,swaps);
            break;
        case 2:
            printf("\nusing selection sort...\n");
            selection_sort();
            printf("comparisons: %d, swaps: %d\n",comparisons,swaps);
            break;
        case 3:
            printf("\nusing insertion sort...\n");
            insertion_sort();
            printf("comparisons: %d, swaps: %d\n",comparisons,swaps);
            break;
        case 4:
            printf("\nusing merge sort...\n");
            comparisons=0;
            swaps=0;
            merge_sort(0,n-1);
            printf("comparisons: %d, swaps: not applicable for merge sort\n",comparisons);
            break;
        default:
            printf("invalid choice\n");
            return 0;
    }
    
    printf("\nsorted array: ");
    display();
    
    return 0;
}