#include <stdio.h>
#include <stdlib.h>

// structure for Single LinkedList
typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node *head = NULL; // LinkedList Head

/* The Present List is a Global Node or List which can be accessed 
by any function without passing as an actual parameter and its lifetime is same as the program or throughout the executuion

Iff written in 'main' function the developer has to pass in LinkedList as double pointer parameter and can be only accessed by the main approved funtion
*/


// Insertion done at the Head
void insertAtBeginning(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Insertion at the Tail
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

// removing a Node
void Remove(int value) {
    Node *temp = head;
    Node *prev = NULL;
    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Element Not Found!");
        return;
    }
    if(prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    
    free(temp);
}

// Displaying Single LinkedList
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
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);
    insertAtBeginning(4);
    insertAtBeginning(5);
    insertAtBeginning(6);

    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);

    Remove(6);

    Display();

    return 0;
}