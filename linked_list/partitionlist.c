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
 
int countS(listnode *A, int B)
{
    listnode* itrA=A;
    int count=0;
    while(itrA!=NULL)
    {
        if(itrA->val < B)
        {
            count++;
        }
        itrA=itrA->next;
    }
    return count;
}
listnode* partition(listnode* A, int B) {
    listnode *itrA=A;
    listnode *itrS=A;
    listnode *itrL=A;
    int sflag=0, lflag=0, temp, end=0;
    int count=countS(A,B);
    
    while(itrS!=NULL && itrL!=NULL)
    {
        while(itrL->val < B )
        {
            itrL=itrL->next;
            if(itrL==NULL)
            {
                end=1;
                break;
            }
            lflag++;
        }
        
        while(itrS->val >= B || sflag<=lflag)
        {
            itrS=itrS->next;
            if(itrS==NULL)
            {
                end=1;
                break;
            }
            sflag++;
        }
        
        if(end==1)
        {
            break;
        }
        
        if(lflag < sflag)
        {
            temp= itrS->val;
            itrS->val=itrL->val;
            itrL->val=temp;
            
        }
        itrS=itrS->next;
        itrL=itrL->next;
    }
    
    
    
    return A;
}

