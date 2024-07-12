#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    float cff;
    int exp;
    struct node *next;
} Node;

Node *NewTerm(float cff, int exp) {
    Node* newNode = (Node *)malloc(sizeof(Node));

    newNode->cff = cff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

Node* push(Node* head, float cff, int exp) {
    Node* newNode = NewTerm(cff, exp);
    if(head == NULL) {
        head = newNode;
        return head;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

Node* Domain() {
    Node* head = NULL;
    int terms;
    printf("Enter Number of Terms: ");
    scanf("%d", &terms);

    for(int i = 1; i <= terms; i++) {
        float cff;
        int exp;
        printf("Enter Co-Efficient of Term %d: ", i);
        scanf("%f", &cff);
        printf("Enter Exponent of Term %d: ", i);
        scanf("%d", &exp);

        head = push(head, cff, exp);
    }

    return head;
}

void peek(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        printf("(%.2f)x ^ %d %c ", temp->cff, temp->exp, (temp->next != NULL) ? '+' : '\n');
        temp = temp->next;
    }
}

int main() {
    Node *poly = Domain();
    peek(poly);
    return 0;
}