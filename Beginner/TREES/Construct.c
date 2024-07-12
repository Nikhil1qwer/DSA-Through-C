#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;


TreeNode* Node(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void PreOrder(TreeNode* root) {
    if(!root) return;

    printf("%d ", root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}

void LevelOrder(TreeNode* root) {
    if(!root) return;

    TreeNode** queue = (TreeNode**) malloc (sizeof(TreeNode*));
    int top = 0, rear = 0;
    queue[rear] = root;
    rear++;
    while(top < rear) {
        TreeNode* cur = queue[top++];
        printf("%d ", cur->val);

        if(cur->left) {
            queue = (TreeNode**) realloc(queue, (rear + 1) * sizeof(TreeNode*));
            queue[rear++] = cur->left;
        }

        if(cur->right) {
            queue = (TreeNode**) realloc(queue, (rear + 1) * sizeof(TreeNode*));
            queue[rear++] = cur->right;
        }

        free(cur);
    }
}

int main() {
    int levels;
    printf("Enter levels: ");
    scanf("%d", &levels);

    int nodes = (int)pow(2, levels) - 1;
    
    TreeNode** queue = (TreeNode**)malloc(nodes * sizeof(TreeNode*));

    int val, choice;
    for(int i = 0; i < nodes; i++) {

        printf("Index: %d \n Enter 1 -> node \n Enter 2 -> NULL\n", i);
        scanf("%d", &choice);

        if(choice == 1) {

            printf("Enter Value: ");
            scanf("%d", &val);
            queue[i] = Node(val);

        } else if(choice == 2) {

            queue[i] = NULL;

        } else {

            printf("Invalid\n");

        }
    }

    for(int i = 0; i < nodes / 2; i++) {
        if(!queue[i]) continue;
        queue[i]->left = queue[2 * i + 1];
        queue[i]->right = queue[2 * i + 2];
    }

    TreeNode* root = queue[0];
    PreOrder(root);
}