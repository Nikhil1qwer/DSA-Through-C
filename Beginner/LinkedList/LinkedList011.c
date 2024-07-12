#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

Node* NewNode(int data) { // constructor
    Node* newNode = (Node *) malloc (sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    Node *newNode = NewNode(data);

    if(head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    Node *newNode = NewNode(data);

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

void InsertAtPos(int data, int position) {
    Node* newNode = NewNode(data);
    
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

void DeleteAtHead() {
    if(head == NULL) {
        printf("List is Empty, No deletion is possible.");
        return;
    }
    if(head->next == NULL) {
        head = NULL;
        return;
    }
    Node* del = head;
    head = head->next;
    free(del);
}

void DeleteAtTail() {
    if(head == NULL) {
        printf("List is Empty, No deletion is possible.");
        return;
    }
    if(head->next == NULL) {
        head = NULL;
        return;
    }

    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = NULL;
    free(del);
}

void DeleteAtPos(int data, int position) {
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

void displayList() {
    Node *temp = head;

    if(head == NULL) {
        printf("No Nodes To Display\n");
        return;
    }

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }   printf("NULL\n");
}

int main() {
    int choice;
    int data;
    int pos;

    do {
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Data to be Inserted at Head: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                printf("Insertion is Succesfull\n");
                break;
            case 2:
                printf("Enter Data to be Inserted at End: ");
                scanf("%d", &data);
                insertAtEnd(data);
                printf("Insertion is Succesfull\n");
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data to Enter at Position -> %d: ", pos);
                scanf("%d", &data);
                InsertAtPos(data, pos);
                printf("Insertion is Successfull\n");
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data to Delete at Position -> %d: ", pos);
                scanf("%d", &data);
                DeleteAtPos(data, pos);
                printf("Deletion is Successfull\n");
                break;
            case 5:
                printf("List: ");
                displayList();
                break;
            case 6:
                DeleteAtHead();
                printf("Deletion at Head is Successfull\n");
                break;
            case 7:
                DeleteAtTail();
                printf("Deletion at Tail is Successfull\n");
                break;
            default:
                printf("Exiting Program!");
                exit(0);
        }
    } while(true);

    return 0;
}