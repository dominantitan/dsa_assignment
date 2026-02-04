// 1. Write a program to check if any given mathematical expression has balanced number of
// parentheses or not?
// Run the program by testing following expression-
// ⇒a + (b − c) ∗ (d
// ⇒m + [a − b ∗ (c + d ∗ {m)]
// ⇒a + (b − c)
// Hint: Use stack

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

struct Stack {
    int top;
    char items[MAX];
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char input) {
    if (stack->top < MAX - 1) {
        stack->items[++(stack->top)] = input;
    }
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        return '\0';
    }
    char popped = stack->items[(stack->top)--];
    return popped;
}

bool isOpeningBracket(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool isClosingBracket(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') || (opening == '[' && closing == ']') || (opening == '{' && closing == '}');
}

bool areParenthesesBalanced(char* expression) {
    struct Stack stack;
    initStack(&stack);
    
    int length = strlen(expression);
    
    for (int i = 0; i < length; i++) {
        if (isOpeningBracket(expression[i])) {
            push(&stack, expression[i]);
        }
        else if (isClosingBracket(expression[i])) {
            if (isEmpty(&stack)) {
                return false; //more closing brackets than opening ones
            }
            
            char openingBracket = pop(&stack);
            if (!isMatchingPair(openingBracket, expression[i])) {
                return false; //no proper pair
            }
        }
    }
    //if stack is empty, all brackets are balanced
    return isEmpty(&stack);
}

int main() {
    char expressions[][50] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };
    
    //number of expressions
    int numExpressions = sizeof(expressions) / sizeof(expressions[0]);
    
    for (int i = 0; i < numExpressions; i++) {
        printf("Expression %d: %s\n", i + 1, expressions[i]);
        
        if (areParenthesesBalanced(expressions[i])) {
            printf("Result:balanced\n");
        } else {
            printf("Result:not balanced\n");
        }
    }
    
    return 0;
}