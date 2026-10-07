#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    int i = 0;
    int operand1, operand2, result;

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            operand1 = pop();
            operand2 = pop();

            switch (exp[i]) {
                case '+': 
                    result = operand2 + operand1; 
                    break;
                case '-': 
                    result = operand2 - operand1;
                    break;
                case '*': 
                    result = operand2 * operand1;
                    break;
                case '/': 
                    result = operand2 / operand1; 
                    break;
            }
            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);
    return 0;
}