#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node* head = NULL;

Node* NewNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBegining(Node* newNode) {
    newNode->next = head;

    if(head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtEnd(Node* newNode) {
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

void insertAtPosition(Node* newNode, int pos) {
    if(pos == 1) {
        insertAtBegining(newNode);
        return;
    }

    Node* cur = head;
    for(int i = 1; i < pos - 1 && cur != NULL; i++) {
        cur = cur->next;
    }

    if(cur == NULL) {
        printf("Invalid Position\n");
        return;
    }

    newNode->next = cur->next;
    newNode->prev = cur;

    if(cur->next != NULL) {
        cur->next->prev = newNode;
    }

    cur->next = newNode;
}

void deleteAtHead() {
    Node* del = head;

    if(!head) {
        printf("List is Empty\n");
        return;
    }

    if(!head->next) {
        head = NULL;
        return;
    }

    head = head->next;
    if(head != NULL) {
        head->prev = NULL;
    }

    free(del);
}

void deleteAtTail() {
    if(!head) {
        printf("List is Empty\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    Node* cur = head;
    Node* prev = NULL;
    while(cur->next) {
        prev = cur;
        cur = cur->next;
    }

    Node* del = cur;
    prev->next = NULL;

    free(del);
}

void deleteAtPos(int pos) {
    if(pos == 1) {
        deleteAtHead();
        return;
    }

    Node* cur = head;
    Node* prev = NULL;
    for(int i = 1; i < pos - 1 && cur != NULL; i++) {
        prev = cur;
        cur = cur->next;
    }

    if(cur == NULL) {
        printf("Invalid Position\n");
        return;
    }

    Node* del = cur->next;
    cur->next = del->next;
    if(del->next != NULL) {
        del->next->prev = cur;
    }

    free(del);
}


void DisplayList() {
    Node *temp  = head;

    if(!head) {
        printf("List is Empty\n");
        return;
    } 
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtBegining(NewNode(10));
    insertAtBegining(NewNode(100));
    insertAtBegining(NewNode(1000));
    insertAtBegining(NewNode(10000));
    insertAtEnd(NewNode(100000));

    DisplayList();

    deleteAtTail();
    
    DisplayList();
    return 0;
}