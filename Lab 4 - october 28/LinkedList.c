#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *current = NULL;

void menu() {
    printf("1. Create\n");
    printf("2. Display\n");
    printf("3. Exit\n");
}

void createlist(int n) {
    int i = 0;
    while (i != n) {
        struct node *new_node;
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->next = NULL;
        printf("Enter the data: ");
        scanf("%d", &new_node->data);
        if (start == NULL) {
            start = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
        i++;
    }
}

void display(struct node *start) {
    if (start == NULL) {
        printf("List empty.\n");
    } else {
        struct node *p = start;
        while (p != NULL) {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, n;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of nodes to create: ");
                scanf("%d", &n);
                createlist(n);
                break;
            case 2:
                display(start);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
