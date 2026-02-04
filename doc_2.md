# Program 2 Documentation

## What does this program do?
This program converts mathematical expressions from infix notation (like we normally write) to postfix notation (used by computers), and then calculates the result. 

**Examples:**
- Infix: `2+3*4` → Postfix: `234*+` → Result: `14`
- Infix: `(2+3)*4` → Postfix: `23+4*` → Result: `20`

## Data Structures Used

### Character Stack (for conversion)
```c
struct CharStack {
    int top;        // points to the top element
    char items[MAX]; // stores operators and parentheses
};
```
- **What it does**: Keeps track of operators during conversion
- **How big**: Can hold up to 100 characters
- **Used for**: Converting infix to postfix

### Integer Stack (for evaluation)
```c
struct IntStack {
    int top;        // points to the top element  
    int items[MAX]; // stores numbers during calculation
};
```
- **What it does**: Stores numbers while calculating the final result
- **How big**: Can hold up to 100 numbers
- **Used for**: Evaluating postfix expressions

## Functions in the Program

### Stack Helper Functions
- **`initCharStack()` / `initIntStack()`**: Sets up empty stacks
- **`isCharStackEmpty()` / `isIntStackEmpty()`**: Checks if stacks are empty
- **`pushChar()` / `pushInt()`**: Puts items on top of stacks
- **`popChar()` / `popInt()`**: Takes items off the top of stacks
- **`peekChar()`**: Looks at the top item without removing it

### Conversion Helper Functions
- **`isOperator()`**: Checks if a character is +, -, *, or /
- **`getPrecedence()`**: Tells us which operators should be done first
  - `*` and `/` have higher precedence (priority) than `+` and `-`

### Main Functions
- **`infixToPostfix()`**: 
  - Converts normal math expressions to postfix form
  - Uses the Shunting Yard algorithm
  - Handles operator precedence and parentheses correctly

- **`evaluatePostfix()`**: 
  - Takes a postfix expression and calculates the final answer
  - Uses a stack to keep track of numbers during calculation

## How the Conversion Algorithm Works (Shunting Yard)

**For each character in the infix expression:**
1. **If it's a number or letter**: Add it directly to the postfix result
2. **If it's an opening parenthesis `(`**: Push it onto the operator stack
3. **If it's a closing parenthesis `)`**: 
   - Pop operators from stack to result until we find the matching `(`
   - Remove the `(` from stack
4. **If it's an operator** (+, -, *, /):
   - Pop operators with higher or equal precedence to the result
   - Push the current operator onto the stack
5. **At the end**: Pop any remaining operators to the result

## How the Evaluation Works

**For each character in the postfix expression:**
1. **If it's a number**: Push it onto the number stack
2. **If it's an operator**: 
   - Pop two numbers from the stack
   - Do the operation (first popped is second operand)
   - Push the result back onto the stack
3. **At the end**: The final answer is the only number left on the stack

## How main() function works

The main function:
1. **Sets up test data**: Creates several infix expressions to test
2. **For each expression**:
   - Shows the original infix expression
   - Converts it to postfix and displays it
   - Evaluates the postfix to get the final result
   - Shows everything in a nice format

## Test Cases and Results

1. **`2+3*4`**
   - **Postfix**: `234*+`
   - **Logic**: 3*4 happens first (precedence), then +2
   - **Result**: 14

2. **`2*3+4`** 
   - **Postfix**: `23*4+`
   - **Logic**: 2*3 happens first, then +4
   - **Result**: 10

3. **`(2+3)*4`**
   - **Postfix**: `23+4*`
   - **Logic**: Parentheses force 2+3 first, then *4
   - **Result**: 20

4. **`2+3*4-1`**
   - **Postfix**: `234*+1-`
   - **Logic**: 3*4 first, then +2, then -1
   - **Result**: 13

## Sample Output
```
Infix to Postfix Converter & Evaluator

Test 1:
Infix:    2+3*4
Postfix:  234*+
Result:   14

Test 2:
Infix:    2*3+4
Postfix:  23*4+
Result:   10

Test 3:
Infix:    (2+3)*4
Postfix:  23+4*
Result:   20

Test 4:
Infix:    2+3*4-1
Postfix:  234*+1-
Result:   13

```


