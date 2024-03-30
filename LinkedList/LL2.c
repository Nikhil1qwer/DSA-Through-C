#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insertAtPosition(int data, int position) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if(position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for(int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid Position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void removeAtPosition(int position) {
    if(head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    if(position == 1) {
        head = head->next;
        free(temp);
        return;
    }

    for(int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid Position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void reverseList() {
    Node *prevNode = NULL;
    Node *current = head;
    Node *nextNode = NULL;

    while(current != NULL){
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    }
    head = prevNode;
}

void Display() {
    Node *temp = head;
    printf("LinkedList: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);

    insertAtPosition(89, 6);

    removeAtPosition(6);

    reverseList();

    Display();

    return 0;
}