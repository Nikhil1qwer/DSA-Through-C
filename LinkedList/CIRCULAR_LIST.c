#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

Node* NewNode(int data) {
    Node* newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    Node* newNode = NewNode(data);
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    head = newNode;
    temp->next = head;
}

void insertAtEnd(int data) {
    Node* newNode = NewNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void insertAtPos(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    Node* newNode = NewNode(data);
    Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count < pos - 1) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    int count = 0;

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    while (temp->next != head && count < pos - 1) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count < pos - 1) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    Node* toDelete = head;
    if (head->next == head) { // Only one node in the list
        head = NULL;
    } else {
        head = head->next;
        temp->next = head;
    }

    free(toDelete);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) { // Only one node in the list
        head = NULL;
    } else {
        prev->next = head;
    }

    free(temp);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf(" (Head)\n");
}

int main() {
    int choice;
    int data;
    int pos;

    do {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Display List\n");
        printf("6. Delete at Head\n");
        printf("7. Delete at Tail\n");
        printf("8. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Data to be Inserted at Head: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                printf("Insertion is Successful\n");
                break;
            case 2:
                printf("Enter Data to be Inserted at End: ");
                scanf("%d", &data);
                insertAtEnd(data);
                printf("Insertion is Successful\n");
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data to Enter at Position -> %d: ", pos);
                scanf("%d", &data);
                insertAtPos(data, pos);
                printf("Insertion is Successful\n");
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                printf("Deletion is Successful\n");
                break;
            case 5:
                printf("List: ");
                displayList();
                break;
            case 6:
                deleteAtBeginning();
                printf("Deletion at Head is Successful\n");
                break;
            case 7:
                deleteAtEnd();
                printf("Deletion at Tail is Successful\n");
                break;
            case 8:
                printf("Exiting Program!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    } while(true);

    return 0;
}
