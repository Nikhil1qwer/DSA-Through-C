#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void push(int data) {
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head != NULL) {
        newNode->next = head;
    }
    head = newNode;
}

int peek() {
    if(!head) {
        printf("Stack is Empty");
        return 0;
    }
    int val = head->data;
    
    return val;
}

void pop() {
    if(!head) {
        printf("Stack is Empty");
        return;
    }
    if(head->next == NULL) {
        head = NULL;
    } else {
        head = head->next;
    }
}

void display() {
    if(!head) {
        printf("Stack is Empty");
        return;
    }
    Node* temp = head;
    printf("(top) ");
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("(bottom)");
}

int isEmpty() {
    return head == NULL;
}

int getSize() {
    int size = 0;
    if(!head) {
        return size;
    }
    Node* temp = head;
    while(temp) {
        temp = temp->next;
        size++;
    }
    return size;
}

int main() {
    int choice, data;

    do {
        printf("\n\n1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. isEmpty\n");
        printf("5. getSize\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                    scanf("%d", &data);
                    push(data);
                    break;
            case 2:
                    pop();
                    break;
            case 3:
                    printf("Top Element is: %d", peek());
                    break;
            case 4:
                    if(isEmpty()) {
                        printf("Stack is Empty\n");
                    } else {
                        printf("Stack is Not Empty\n");
                    }
                    break;
            case 5:
                    printf("Stack size: %d\n", getSize());
                    break;
            case 6:
                    display();
                    break;
            case 7:
                    exit(0);
            default: 
                    printf("Invalid Choice\n");
        }
    } while(true);
}