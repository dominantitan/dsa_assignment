//2. Write a program to convert an infix mathematical expression to postfix and evaluate it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

// Stack for characters (used in infix to postfix conversion)
struct CharStack {
    int top;
    char items[MAX];
};

// Stack for integers (used in postfix evaluation)
struct IntStack {
    int top;
    int items[MAX];
};

// Initialize character stack
void initCharStack(struct CharStack* stack) {
    stack->top = -1;
}

// Initialize integer stack
void initIntStack(struct IntStack* stack) {
    stack->top = -1;
}

// Check if character stack is empty
bool isCharStackEmpty(struct CharStack* stack) {
    return stack->top == -1;
}

// Check if integer stack is empty
bool isIntStackEmpty(struct IntStack* stack) {
    return stack->top == -1;
}

// Push character to stack
void pushChar(struct CharStack* stack, char item) {
    if (stack->top < MAX - 1) {
        stack->items[++(stack->top)] = item;
    }
}

// Push integer to stack
void pushInt(struct IntStack* stack, int item) {
    if (stack->top < MAX - 1) {
        stack->items[++(stack->top)] = item;
    }
}

// Pop character from stack
char popChar(struct CharStack* stack) {
    if (stack->top == -1) {
        return '\0';
    }
    return stack->items[(stack->top)--];
}

// Pop integer from stack
int popInt(struct IntStack* stack) {
    if (stack->top == -1) {
        return 0;
    }
    return stack->items[(stack->top)--];
}

// Peek top character from stack
char peekChar(struct CharStack* stack) {
    if (stack->top == -1) {
        return '\0';
    }
    return stack->items[stack->top];
}

// Check if character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Get precedence of operator
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct CharStack operatorStack;
    initCharStack(&operatorStack);
    
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        char current = infix[i];
        
        // If character is a digit or letter, add to output
        if (isalnum(current)) {
            postfix[j++] = current;
        }
        // If character is '(', push to stack
        else if (current == '(') {
            pushChar(&operatorStack, current);
        }
        // If character is ')', pop until '(' is found
        else if (current == ')') {
            while (!isCharStackEmpty(&operatorStack) && peekChar(&operatorStack) != '(') {
                postfix[j++] = popChar(&operatorStack);
            }
            popChar(&operatorStack); // Remove the '(' from stack
        }
        // If character is an operator
        else if (isOperator(current)) {
            while (!isCharStackEmpty(&operatorStack) && 
                   peekChar(&operatorStack) != '(' &&
                   getPrecedence(peekChar(&operatorStack)) >= getPrecedence(current)) {
                postfix[j++] = popChar(&operatorStack);
            }
            pushChar(&operatorStack, current);
        }
        i++;
    }
    
    // Pop remaining operators from stack
    while (!isCharStackEmpty(&operatorStack)) {
        postfix[j++] = popChar(&operatorStack);
    }
    
    postfix[j] = '\0'; // Null terminate the string
}

// Evaluate postfix expression
int evaluatePostfix(char* postfix) {
    struct IntStack valueStack;
    initIntStack(&valueStack);
    
    int i = 0;
    
    while (postfix[i] != '\0') {
        char current = postfix[i];
        
        // If character is a digit, push its value to stack
        if (isdigit(current)) {
            pushInt(&valueStack, current - '0');
        }
        // If character is an operator, pop two operands and perform operation
        else if (isOperator(current)) {
            if (!isIntStackEmpty(&valueStack)) {
                int operand2 = popInt(&valueStack);
                int operand1 = isIntStackEmpty(&valueStack) ? 0 : popInt(&valueStack);
                
                int result;
                switch (current) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        if (operand2 != 0) {
                            result = operand1 / operand2;
                        } else {
                            printf("Error: Division by zero!\n");
                            return 0;
                        }
                        break;
                    default:
                        result = 0;
                }
                pushInt(&valueStack, result);
            }
        }
        i++;
    }
    
    // The final result should be the only element left in stack
    return isIntStackEmpty(&valueStack) ? 0 : popInt(&valueStack);
}

int main() {
    char infixExpressions[][50] = {
        "2+3*4",
        "2*3+4",
        "(2+3)*4",
        "2+3*4-1"
    };
    
    int numExpressions = sizeof(infixExpressions) / sizeof(infixExpressions[0]);
    
    printf("Infix to Postfix Converter & Evaluator\n");
    
    for (int i = 0; i < numExpressions; i++) {
        char postfixResult[MAX];
        
        printf("Test %d:\n", i + 1);
        printf("Infix:    %s\n", infixExpressions[i]);
        
        // Convert infix to postfix
        infixToPostfix(infixExpressions[i], postfixResult);
        printf("Postfix:  %s\n", postfixResult);
        
        // Evaluate postfix expression
        int result = evaluatePostfix(postfixResult);
        printf("Result:   %d\n", result);

    }
    
    return 0;
}