/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* currentNode = head;
    struct ListNode* prev = NULL;
    while (currentNode != NULL) {
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = currentNode->val;
        newNode->next = prev;
        currentNode = currentNode->next;
        prev = newNode;
    }
    return prev;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *dummy=NULL;
    while(head!=NULL){
        struct ListNode* next=head->next;
        head->next =dummy;
        dummy=head;
        head =next;
    }
    return dummy;
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Base case: empty list or single node
    }

    struct ListNode* newHead = reverseList(head->next); // Recursively reverse the rest of the list
    head->next->next = head; // Reverse the link for the current node
    head->next = NULL; // Set the current node's next pointer to NULL to terminate the list

    return newHead; // Return the new head of the reversed list
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////