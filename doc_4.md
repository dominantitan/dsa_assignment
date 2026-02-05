# Program 4 Documentation

## Data Structures
- **struct node**: Doubly linked list node with data, next pointer, and prev pointer
- **head**: Global pointer to first node

## Functions Implemented
- **display()**: Shows all elements in the list
- **insert_at_end(int val)**: Adds new node at the end of list
- **insert_after(int after_val, int new_val)**: Inserts new node after specified value
- **delete_node(int val)**: Removes node with given value

## Main Method Organization
1. Shows menu with options
2. Takes user choice
3. Calls appropriate function based on choice
4. Repeats until user exits

## Sample Output
```
1.insert at end 2.insert after 3.delete 4.display 5.exit
choice: 1
enter value: 10

1.insert at end 2.insert after 3.delete 4.display 5.exit
choice: 1
enter value: 20

1.insert at end 2.insert after 3.delete 4.display 5.exit
choice: 4
list: 10 20 

1.insert at end 2.insert after 3.delete 4.display 5.exit
choice: 2
insert after which value: 10
enter new value: 15

1.insert at end 2.insert after 3.delete 4.display 5.exit
choice: 4
list: 10 15 20 
```
