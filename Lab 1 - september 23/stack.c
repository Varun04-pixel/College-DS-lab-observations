#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stack[MAX];
int top = -1;

void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack Overflow\n\n");
    } else {
        printf("Enter the element: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Successfully pushed %d onto the stack.\n\n", value);
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n\n");
    } else {
        printf("Popped element: %d\n\n", stack[top]);
        top--;
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty.\n\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n\n");
    }
}

void main() {
    int choice, i = 0;
    while (i != 1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                i = 1;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}