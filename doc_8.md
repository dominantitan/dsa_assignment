# Program 8 Documentation

## Data Structures
- **arr[1000]**: Main array to store random numbers
- **temp[1000]**: Backup array to preserve original data
- **comparisons**: Counter for comparison operations
- **swaps**: Counter for swap operations
- **n**: Number of elements

## Functions Implemented
- **generate_random()**: Creates N random numbers between 1-1000
- **display()**: Shows current array contents
- **bubble_sort()**: O(n²) algorithm with adjacent swapping
- **selection_sort()**: O(n²) algorithm finding minimum each iteration
- **insertion_sort()**: O(n²) algorithm inserting elements in sorted position
- **merge_sort()**: O(n log n) divide and conquer algorithm
- **merge()**: Helper function to merge sorted subarrays
- **copy_array()**: Backs up original array
- **restore_array()**: Restores original array

## Main Method Organization
1. Takes number of elements from user
2. Generates random array and displays it
3. Shows sorting algorithm menu
4. Executes chosen algorithm with performance counting
5. Displays sorted array and statistics

## Sample Output
```
enter number of elements (max 1000): 8

original array: 234 567 123 890 456 789 321 654 

choose sorting algorithm:
1. bubble sort
2. selection sort
3. insertion sort
4. merge sort
choice: 1

using bubble sort...
comparisons: 28, swaps: 15

sorted array: 123 234 321 456 567 654 789 890 
```
