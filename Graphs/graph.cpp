#include <stdio.h>
#include <stdlib.h>

#define scan(x) scanf("%d", &x);
#define MAX_SIZE 1000

typedef struct node {
    int val;
    struct node* next;
} Node;

typedef struct graph {
    Node* head[MAX_SIZE];
} Graph;

Graph* AList = NULL;

Node* NewNode(int data) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

int** AdjacencyMatrix(int size, int edges) {
    int **graph = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++) {
        graph[i] = (int *)malloc(size * sizeof(int));
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < edges; i++) {
        int u, v;
        scan(u); scan(v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    return graph;
}

void insertAtEnd(Node **graph, Node* newNode) {
    if(!*graph) {
        *graph = newNode;
        return;
    }
    
    Node* temp = *graph;
    while(temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void AdjacencyList(int size, int edges) {
    AList = (Graph *)malloc(sizeof(Graph));
    for (int i = 0; i < size; i++) {
        AList->head[i] = NULL;
    }

    for (int i = 0; i < edges; i++) {
        int u, v;
        scan(u); scan(v);

        Node* vNode = NewNode(v);
        Node* uNode = NewNode(u);

        insertAtEnd(&AList->head[u], vNode);
        insertAtEnd(&AList->head[v], uNode);
    }
}

void graphBFS() {
    
}

int main() {
    int n, e;
    scan(n); scan(e);

    AdjacencyList(n, e);
}