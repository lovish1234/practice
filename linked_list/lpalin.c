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
 * @Output Integer
 */

listnode* endofList(listnode* A)
{
    listnode* ans=A;
    while(ans!=NULL)
    {
        ans=ans->next;
    }
    return ans;
}

int listLength(listnode* A)
{
    listnode* itr=A;
    int count=0;
    while(itr!=NULL)
    {
        itr=itr->next;
        count++;
    }
    return count;
}

listnode* reverseList(listnode* A) {
    listnode* prev=NULL;
    
    listnode* current=A;
    listnode* n;
    while(current!=NULL)
    {
        n=current->next;
        current->next=prev;
        prev=current;
        current=n;
    }
    return prev;
}

int lPalin(listnode* A) 
{
    int A_length= listLength(A);
    if(A_length==0 || A_length==1)
    {
        return 1;
    }
    //printf("%d\n",A_length);
    int i;
    listnode* B=A;
    listnode* C=A;
    if(A_length%2==0)
    {
        for(i=0;i<(A_length/2);i++)
        {
            B=B->next;
        }
        for(i=0;i<((A_length/2)-1);i++)
        {
            C=C->next;
        }
        C->next=NULL;
        
    }
    else
    {
        for(i=0;i<((A_length/2)+1);i++)
        {
            B=B->next;
        }
        for(i=0;i<((A_length/2)-1);i++)
        {
            C=C->next;
        }
        C->next=NULL;
    }
    
    C=reverseList(A);
    listnode* itrB =B;
    listnode* itrC =C;
    
    /*
   
    
    listnode* itrB1 =B;
    listnode* itrC1 =C;
    
    while(itrB1!=NULL)
    {
        printf("%d ",itrB1->val);
        itrB1=itrB1->next;
        
    }
    printf("\n");
    
    
    
    while(itrC1!=NULL)
    {
        printf("%d ",itrC1->val);
        itrC1=itrC1->next;
        
    }
    printf("\n");
    */
    
    
    
    while(itrB!=NULL)
    {
        if((itrB->val)!=(itrC->val))
        {
            return 0;
        }
        itrB=itrB->next;
        itrC=itrC->next;
    }
    
    
    return 1;
}
