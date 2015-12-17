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
 
int listLength(listnode *A)
{
    listnode* itr=A;
    int count=0;
    while(itr!=NULL)
    {
        //printf("%d\n",count);
        itr=itr->next;
        count++;
    }
    return count;
}
listnode* mergeTwoLists(listnode* A, listnode* B) {
    
    listnode* itrA=A;
    listnode* itrB=B;
    
    int A_length=listLength(A);
    int B_length=listLength(B);
    int i=0,j=0;
    
    if(A_length==0 && B_length==0)
    {
        return A;
    }
    
    if(A_length==0)
    {
        return B;
    }
    
    if(B_length==0)
    {
        return A;
    }
    
    
    //printf("%d %d \n",A_length,B_length);
    //int C_length=A_length+B_length;
    
    listnode* C= (listnode *)malloc(sizeof(listnode));
    //C->next=NULL;
    listnode* itrC=C;
    
    while(i<A_length && j<B_length)
    {
        
        if(itrA->val < itrB->val)
        {
            itrC->val=itrA->val;
            itrA=itrA->next;
            i++;
        }
        else 
        {
            itrC->val=itrB->val;
            itrB=itrB->next;
            j++;
        }
       // printf("%d\n",itrC->val);
        
        listnode* N= (listnode *)malloc(sizeof(listnode));
        //N->next=NULL;
        itrC->next=N;
        itrC=N;
        itrC->next=NULL;
        
    }
    
    if(i==A_length)
    {
        while(j<B_length)
        {
            itrC->val=itrB->val;
            itrB=itrB->next;
            j++;
            
           // printf("%d\n",itrC->val);
           if(j!=B_length)
           {
                listnode* N= (listnode *)malloc(sizeof(listnode));
                //N->next=NULL;
                itrC->next=N;
                itrC=N;
           }
            
        }
        
    }
    
    if(j==B_length)
    {
        while(i<A_length)
        {
            itrC->val=itrA->val;
            itrA=itrA->next;
            i++;
           
           // printf("%d\n",itrC->val);
            if(i!=A_length)
            {
                listnode* N= (listnode *)malloc(sizeof(listnode));
                //N->next=NULL;
                itrC->next=N;
                itrC=N;
            }
            
        }
        
        
    }
    itrC->next=NULL;
  
    
    return C;
    
}
