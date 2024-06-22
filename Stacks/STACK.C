#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000

typedef struct stack {
    int top;
    int item[MAX_SIZE];
} Stack;

Stack* stack = NULL;

void initialize() {
    stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
}

int getSize() {
    return stack->top;
}

bool isEmpty() {
    return stack->top == -1;
}

void push(int data) {
    if(getSize() == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }

    stack->item[++stack->top] = data;
}

void pop() {
    if(isEmpty()) {
        printf("Stack is Empty\n");
        return;
    }
    stack->item[--stack->top];
}

int top() {
    if(isEmpty()) {
        return -1;
    }
    return stack->item[stack->top];
}

void display(Stack* temp) {
    if(isEmpty()) {
        printf("Stack is Empty\n");
        return;
    }

    while(!isEmpty()) {
        printf("%d ", top());
        pop();
    }
}

int main() {
    int choice, data;

    do {
        printf("\n\n1. Initialize Stack\n");
        printf("2. push\n");
        printf("3. pop\n");
        printf("4. peek\n");
        printf("5. isEmpty\n");
        printf("6. getSize\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                    initialize();
                    break;
            case 2:
                    scanf("%d", &data);
                    push(data);
                    break;
            case 3:
                    pop();
                    break;
            case 4:
                    if(top() == -1) {
                        printf("Stack is Empty\n");
                    } else {
                        printf("Top Element is: %d", top());
                    }
                    break;
            case 5:
                    if(isEmpty()) {
                        printf("Stack is Empty\n");
                    } else {
                        printf("Stack is Not Empty\n");
                    }
                    break;
            case 6:
                    printf("Stack size: %d\n", getSize());
                    break;
            case 7:
                    display(stack);
                    break;
            case 8:
                    exit(0);
            default: 
                    printf("Invalid Choice\n");
        }
    } while(true);
}