#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insertAtBegining(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = head;

    if(head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtEnd(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void DisplayList() {
    Node *temp  = head; 
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

int main() {
    insertAtBegining(10);
    insertAtBegining(10);
    insertAtBegining(10);
    insertAtBegining(10);

    insertAtEnd(555);

    DisplayList();
    return 0;
}