#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int row;
    int col;
    int data;
    struct node* next;
} Node;

Node* head = NULL;

Node* NewNode(int row, int col, int data) {
    Node* newNode = (Node *)malloc(sizeof(Node));

    newNode->row = row;
    newNode->col = col;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtEnd(int row, int col, int data) {
    Node* newNode = NewNode(row, col, data);
    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void displayList() {
    Node *temp = head;

    printf("Non-Zero ELements of the given sparse matrix: \n");
    printf("Row\tCol\tVal\n");

    if(head == NULL) {
        printf("No Nodes To Display\n");
        return;
    }

    while(temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->data);
        temp = temp->next;
    }
}

void ReadMatrix() {
    int row, col;
    printf("Enter Row: ");
    scanf("%d", &row);
    printf("Enter Column: ");
    scanf("%d", &col);
    
    int mat[row][col];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(mat[i][j] != 0) {
                insertAtEnd(i, j, mat[i][j]);
            }
        }
    }

    printf("LinkedList Initialised\t");
}

int main() {
    int choice;
    int row, col, data, pos;

    do {
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                ReadMatrix();
                printf("Rendered\n");
                break;
            case 2:
                displayList();
                break;
            default:
                exit(0);
        }
    } while(true);

    return 0;
}