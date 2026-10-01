#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char item) {
    if(top>MAX-1 ) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if(top<0) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek() {
    return stack[top];
}

int getPrecedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i=0, j=0;
    int ch;
    while(infix[i] != '\0') {
        ch = infix[i];

        if(isalnum(ch)) {
            postfix[j++] = ch;
        } else if(ch == '(') {
            push(ch);
        } else if(ch == ')') {
            while(top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while(top != -1 && getPrecedence(peek()) >= getPrecedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }
    while(top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression is %s\n", postfix);
}