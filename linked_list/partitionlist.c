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
listnode* partition(listnode* A, int B) {
    
    
    listnode *itrA=A;
    listnode *S=(listnode*)malloc(sizeof(listnode));
    listnode *L=(listnode*)malloc(sizeof(listnode));
    listnode* itrS=S, *prevS=A;
    listnode* itrL=L, *prevL=A;
    int sflag=0, lflag=0;
    
    
    while(itrA!=NULL)
    {
        if(itrA->val<B)
        {
            itrS->val=itrA->val;
            prevS=itrS;
            itrS->next=(listnode*)malloc(sizeof(listnode));
            itrS=itrS->next;
            //itrS->next=L;
            sflag=1;
        }
        else
        {
            itrL->val=itrA->val;
            prevL=itrL;
            itrL->next=(listnode*)malloc(sizeof(listnode));
            itrL=itrL->next;
            //itrL->next=NULL;
            lflag=1;
        }
        itrA=itrA->next;
    }
    
    if(sflag==1 && lflag==1)
    {
  
        prevS->next=L;
        prevL->next=NULL;
        return S;
    }
    else
    {
        return A;
    }
}

