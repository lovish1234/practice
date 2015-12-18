/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* swapPairs(listnode* A) {
    listnode* prev=A;
    listnode* curr=A->next;
    int temp;
    while(curr!=NULL)
    {
        temp=prev->val;
        prev->val=curr->val;
        curr->val=temp;
        prev=prev->next->next;
        if(prev!=NULL)
        {
            curr=curr->next->next;
        }
        else
        {
            curr=NULL;
        }
    }
    return A;
}
