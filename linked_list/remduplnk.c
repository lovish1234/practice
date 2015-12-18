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
listnode* deleteDuplicates(listnode* A) {
    listnode *prev=A;
    listnode *curr=A->next;
    
    while(curr!=NULL)
    {
        if(prev->val==curr->val)
        {
            prev->next=curr->next;
            curr=prev->next;
        }
        else
        {
            prev=prev->next;
            curr=curr->next;
        }
    }
    return A;
    
}
