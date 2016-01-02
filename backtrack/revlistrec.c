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
 
listnode* reverseListV(listnode* A)
{
    if(A->next==NULL)
    {
        listnode *head=A;
        return head;
    }
    
    listnode* head=reverseListV(A->next);
    listnode *B= A->next;
    B->next=A;
    A->next=NULL;
    return head;

}

listnode* reverseList(listnode* A) {
    listnode* head = reverseListV(A);
    return head;
}

