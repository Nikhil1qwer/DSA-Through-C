#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define esc printf("\n");

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* head = NULL;

TreeNode* New(int data) {
    TreeNode* newNode = (TreeNode *) malloc (sizeof(TreeNode));
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void ConstructBST(TreeNode* newNode) {
    if(!head) {
        head = newNode;
        return;
    }

    TreeNode* cur = head;
    TreeNode* root = NULL;
    
    while(cur) {
        root = cur;
        if(cur->val > newNode->val) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    if(root->val > newNode->val) {
        root->left = newNode;
    } else {
        root->right = newNode;
    }
}

void inOrder(TreeNode* root) {
    if(!root) return;

    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

void preOrder(TreeNode* root) {
    if(!root) return;
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(TreeNode* root) {
    if(!root) return;
    
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

bool search(TreeNode* root, int key) {
    if(!root) return false;
    if(root->val == key) {
        return true;
    }

    if(root->val > key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    int choice, data, size, key;
    do {
        printf("1. Construct Binary Search Tree\n");
        printf("2. PreOrder Traversal\n");
        printf("3. InOrder Traversal\n");
        printf("4. PostOrder Traversal\n");
        printf("5. Search in BST\n");
        printf("6. Exit\n\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                    printf("Enter No. of Nodes: ");
                    scanf("%d", &size);

                    for(int i = 0; i < size; i++) {
                        scanf("%d", &data);
                        ConstructBST(New(data));
                    }
                    esc;
                    break;
            case 2:
                    preOrder(head);
                    esc;
                    break;
            case 3:
                    inOrder(head);
                    esc;
                    break;
            case 4:
                    postOrder(head);
                    esc;
                    break;
            case 5:
                    printf("Enter Key to Search: ");
                    scanf("%d", &key);
                    if(search(head, key)) {
                        printf("Key is Found!\n");
                    } else {
                        printf("Key is Not Found!\n");
                    }
            case 6:
                    exit(0);
            default: 
                    printf("Invalid Choice\n");
        }
    } while(true);

    return 0;
}