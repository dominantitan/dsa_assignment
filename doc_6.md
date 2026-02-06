# Program 6 Documentation

## Data Structures
- **heap[100]**: Array to store heap elements
- **n**: Number of elements in heap

## Functions Implemented
- **swap(int *a, int *b)**: Swaps two elements
- **max_heapify(int i)**: Maintains max heap property for subtree rooted at index i
- **min_heapify(int i)**: Maintains min heap property for subtree rooted at index i
- **build_max_heap()**: Converts array to max heap
- **build_min_heap()**: Converts array to min heap
- **display()**: Shows current heap elements

## Main Method Organization
1. Takes input array from user
2. Displays original unsorted array
3. Builds and displays max heap
4. Takes input again for min heap
5. Builds and displays min heap

## Sample Output
```
enter no of elements: 6
enter elements: 4 10 3 5 1 8

original array: 4 10 3 5 1 8 
max heap: 10 5 8 4 1 3 

enter elements again for min heap: 4 10 3 5 1 8
min heap: 1 4 3 5 10 8 
```
