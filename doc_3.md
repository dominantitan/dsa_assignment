# Program 3 Documentation

## Data Structures
- **struct node**: Simple linked list node containing integer data and pointer to next node
- **head**: Global pointer to the first node of the linked list

## Functions Implemented
- **insert(int val)**: Inserts a new node at the beginning of the linked list
- **display()**: Traverses and prints the linked list in normal order
- **reverse_print(struct node *temp)**: Recursively traverses and prints the linked list in reverse order

## Main Method Organization
1. Reads number of nodes from user
2. Creates linked list by inserting values at the beginning
3. Displays the normal list
4. Displays the reverse traversal using recursion

## Sample Output
```
enter no of nodes: 5
enter value: 10
enter value: 20
enter value: 30
enter value: 40
enter value: 50
normal list: 50 40 30 20 10 
reverse traversal: 10 20 30 40 50
```
