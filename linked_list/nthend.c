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
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */

int listLength(listnode* A)
{
    listnode *itrA=A;
    int count=0;
    while(itrA!=NULL)
    {
        count++;
        itrA=itrA->next;
    }
    return count;
}

listnode* removeNthFromEnd(listnode* A, int B) {
    int A_length=listLength(A);
    listnode* itrA=A;
    //printf("%d\n",listLength(A));
    if(A_length==1 && B==1)
    {
        return NULL;
    }
    
    if(B>=A_length)
    {
        A=A->next;
      
    }
    else
    {
        int i;
        for(i=0;i<(A_length-B-1);i++)
        {
            //printf("%d\n",itrA->val);
            itrA=itrA->next;
        }
        
        
        if(B==1)
        {
            itrA->next=NULL;
        }
        else
        {
            itrA->next=itrA->next->next;
        }
        
        
     
    }
    
    
    return A;
}
