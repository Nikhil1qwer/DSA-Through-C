#include <stdio.h>
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

void InOrder(TreeNode* root) {
    if(!root) return;

    InOrder(root->left);
    printf("%d ", root->val);
    InOrder(root->right);
}

void PostOrder(TreeNode* root) {
    if(!root) return;

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->val);
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
    TreeNode* root =  Node(10);
    root->left = Node(20);
    root->right = Node(30);
    root->left->left = Node(40);
    root->left->right = Node(50);
    root->right->left = Node(60);
    root->right->right = Node(70);

    do {
        int choice;
        printf("\n1. PreOrder Traversal\n");
        printf("2. InOrder Traversal\n");
        printf("3. PostOrder Traversal\n");
        printf("4. LevelOrder Traversal\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                PreOrder(root);
                break;
            case 2:
                InOrder(root);
                break;
            case 3:
                PostOrder(root);
                break;
            case 4:
                LevelOrder(root);
                break;
            default:
                printf("Invalid Move");
        }
    } while(1);

    return 0;
}