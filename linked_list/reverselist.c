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
 * @input m : Integer
 * @input n : Integer
 * 
 * @Output head pointer of list.
 */
 
int listLength(listnode *A)
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

listnode* reverseBetween(listnode* A, int m, int n) {
    
    if(m==n)
    {
        return A;
    }
    
    if(n==m+1 && listLength(A)==2)
    {
        listnode *B=A->next;
        A->next->next=A;
        A->next=NULL;
        return B;
    }
    
    int i,count=0;
    //listnode *itrA=A;
    listnode *head=A,*prev,*curr,*ne,*tail=A;
    
    // head and tail cannot be null
    for(i=1;i<m-1;i++)
    {
        head=head->next;
    }
    //printf("%d\n",head->val);
    for(i=1;i<n+1;i++)
    {
        tail=tail->next;
    }
    //printf("%d\n",tail->val);
    
    if(m!=1)
    {
        prev=head->next;
        curr=prev->next;
        ne=curr->next;
        while(ne!=tail)
        {
            //printf("%d %d %d\n",prev->val,curr->val,ne->val);
            curr->next=prev;
            prev=curr;
            curr=ne;
            ne=ne->next;
            //printf("%d %d %d\n",prev->val,curr->val,ne->val);
    
        }
        curr->next=prev;
        head->next->next=tail;
        head->next=curr;
        return A;
    }
    
    else
    {
        prev=head;
        curr=prev->next;
        ne=curr->next;
        while(ne!=tail)
        {
            //printf("%d %d %d\n",prev->val,curr->val,ne->val);
            curr->next=prev;
            prev=curr;
            curr=ne;
            ne=ne->next;
            //printf("%d %d %d\n",prev->val,curr->val,ne->val);
    
        }
        curr->next=prev;
        head->next=tail;
        return curr;
        
    }
    
    
    
    
}
