# Program 1 Documentation

## What does this program do?
This program checks if brackets are balanced in math expressions. It works with three types of brackets:
- Round brackets: ( )
- Square brackets: [ ]
- Curly brackets: { }

## Data Structure Used

### Stack
```c
struct Stack {
    int top;        //index of the top element (-1 when empty)
    char items[MAX]; //array to store stack elements
};
```
- **What it does**: Stores opening brackets as we find them
- **How big**: Can hold up to 100 brackets
- **How it works**: Last bracket in, first bracket out (like a stack of plates)

## Functions in the Program

### Basic Stack Functions
- **`initStack()`**: Sets up a new empty stack
- **`isEmpty()`**: Checks if the stack has nothing in it
- **`push()`**: Puts a bracket on top of the stack
- **`pop()`**: Takes the top bracket off the stack

### Helper Functions
- **`isOpeningBracket()`**: Checks if we found an opening bracket like ( [ or {
- **`isClosingBracket()`**: Checks if we found a closing bracket like ) ] or }
- **`isMatchingPair()`**: Checks if opening and closing brackets match (like ( with ) )

### Main Function
- **`areParenthesesBalanced()`**: 
  - Goes through the expression one character at a time
  - Puts opening brackets on the stack
  - When it finds closing brackets, checks if they match with what's on the stack
  - Returns true if everything matches correctly

## How the Algorithm Works

1. **Start** with an empty stack
2. **Go through each character** in the math expression:
   - If it's an opening bracket ( [ { : put it on the stack
   - If it's a closing bracket ) ] } :
     - Check if the stack is empty (this means extra closing bracket)
     - Take the top bracket from stack and see if it matches
     - If they don't match, the expression is wrong
3. **At the end**: If the stack is empty, all brackets are balanced

## How main() function works

The main function:
1. **Sets up test data**: Creates three test expressions to check
2. **Tests each expression**: Runs the balance check on each one
3. **Shows results**: Prints whether each expression is balanced or not
4. **Nice output**: Makes the results easy to read

## Test Cases

1. `"a + (b - c) * (d"` - **NOT BALANCED** (missing closing parenthesis)
2. `"m + [a - b * (c + d * {m)]"` - **NOT BALANCED** (mismatched brackets: `{` closed by `]`)
3. `"a + (b - c)"` - **BALANCED** (properly matched parentheses)

## Sample Output
```
Expression 1: a + (b - c) * (d
Result:not balanced
Expression 2: m + [a - b * (c + d * {m)]
Result:not balanced
Expression 3: a + (b - c)
Result:balanced
```

## Why this works

- **Time**: Takes time equal to the length of the expression (goes through once)
- **Space**: Uses memory equal to the number of opening brackets (worst case)

## Key Features

- Works with all three bracket types: ( ) [ ] { }
- Checks if brackets are in the right order
- Ignores letters, numbers, and math symbols
- Finds common bracket mistakes
