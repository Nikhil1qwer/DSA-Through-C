#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define the stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Global stack variable
Stack stack;

// Initialize an empty stack
void initialize() {
    stack.top = -1;
}

// Check if the stack is empty
bool isEmpty() {
    return stack.top == -1;
}

// Check if the stack is full
bool isFull() {
    return stack.top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack overflow!\n");
        return;
    }
    stack.items[++stack.top] = value;
}

// Pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return -1; // Error code or sentinel value
    }
    return stack.items[stack.top--];
}

// Peek at the top element of the stack without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1; // Error code or sentinel value
    }
    return stack.items[stack.top];
}

void display() {
    while(!isEmpty()) {
        printf("%d ", peek());
        pop();
    }
}

int main() {
    initialize();

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    printf("Top element: %d\n", peek());

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    printf("Top element after popping: %d\n", peek());

    display();

    return 0;
}
