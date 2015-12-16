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
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* getIntersectionNode(listnode* A, listnode* B) {
    listnode *itrA=A;
    listnode *itrB=B;
    
    // 0 means the list a sublist of whole list
    while((itrA)!=NULL)
    {
        itrB=B;
        while((itrB)!=NULL)
        {
           
            if((itrA)==(itrB))
            {
                return itrA;
            }
            
            itrB=itrB->next;  
        }
        itrA=itrA->next;
    }
    return NULL;
}
