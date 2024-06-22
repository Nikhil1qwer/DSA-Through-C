#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define escape printf("\n")
#define scan(x) scanf("%d", &(x));

typedef struct node {
    int val;
    struct node* next;
} Node;

Node* head = NULL;

Node* NewNode(int data) {
    Node* newNode = (Node *) malloc (sizeof(Node));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    Node* newNode = NewNode(data);
    if(!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

Node* tail = NULL;
void insertAtEnd(int data) {
    Node* newNode = NewNode(data);
    if(!head) {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

void deleteAtHead() {
    if(!head) {
        printf("List is Empty\n");
        return;
    }

    if(!head->next) {
        head = NULL;
        return;
    }

    Node* del = head;
    head = head->next;

    free(del);
}

void deleteAtTail() {
    if(!head) {
        printf("List is Empty\n");
        return;
    }

    if(!head->next) {
        head = NULL;
        return;
    }
}

void insertAtPosition(int data, int position) {
    if(position == 1) {
        insertAtBeginning(data);
    }
    Node* newNode = NewNode(data);
    Node* temp = head;
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

void deleteAtPos(int position) {
    if(position == 1) {
        deleteAtHead();
    }

    Node* temp = head;
    Node* prev = NULL;
    for(int i = 1; i < position - 1 && temp != NULL; i++) {
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

void reverseLinkedList() {
    Node* prev = NULL;
    Node* cur = head;
    Node* nxt = NULL;

    while(cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = cur->next;
    }

    head = prev;
}




void searchList(int data) {
    Node* temp = head;
    int count = 1;
    while(temp != NULL) {
        if(temp->val == data) {
            printf("Data is Found at Position %d\n", count);
            return;
        }
        temp = temp->next;
        count++;
    }

    printf("Data Not Found!!");
}

void displayList() {
    Node* temp = head;
    if(!temp) {
        printf("List is Empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

    printf("NULL");
    escape;
}

int main() {
    int choice, data, pos;
    do {
        printf("1. Insertion At Head\n");
        printf("2. Insertion At Tail\n");
        printf("3. Insertion At Position\n");
        printf("4. Delete At Head\n");
        printf("5. Delete At Tail\n");
        printf("6. Delete At Position\n");
        printf("7. Reverse LinkedList\n");
        printf("8. Search In LinkedList\n");
        printf("9. Display LinkedList\n");
        printf("10. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);
        escape;

        switch(choice) {
            case 1:
                printf("Enter Data: ");
                scan(data);
                insertAtBeginning(data);
                escape;
                break;
            case 2:
                printf("Enter Data: ");
                scan(data);
                insertAtEnd(data);
                escape;
                break;
            case 3:
                printf("Enter Data: ");
                scan(data); scan(pos);
                insertAtPosition(data, pos);
                escape;
                break;
            case 4:
                deleteAtHead();
                break;
            case 5:
                deleteAtTail();
                break;
            case 6:
                printf("Enter Position to Delete: ");
                scan(pos);
                deleteAtPos(pos);
                break;
            case 7:
                reverseLinkedList();
                break;
            case 8:
                printf("Enter Data To Search: ");
                scan(data);
                searchList(data);
                break;
            case 9:
                displayList();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
        escape;
    } while(true);

    return 0;
}