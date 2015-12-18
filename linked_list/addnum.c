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

int listLength(listnode* A)
{
    listnode* itr=A;
    int count=0;
    while(itr!=NULL)
    {
        itr=itr->next;
        count++;
        //printf("%d\n",count);
    }
    return count;
}


listnode* addTwoNumbers(listnode* A, listnode* B) {
    //listnode* RA=reverseList(A);
   // listnode* RB=reverseList(B);
    
    listnode *itrA=A;
    listnode *itrB=B;
    //printf("%d %d\n",listLength(A),listLength(B));
    int gLength= (listLength(A)>=listLength(B))?1:0;
    
    
    int carry=0,count=0;
    
    listnode *prevA;
    listnode *prevB;
    
    int prevAV,prevBV;
    while(itrA!=NULL && itrB!=NULL)
    {
        
        prevAV=itrA->val;
        prevBV=itrB->val;
        
        if(gLength==1)
        {
            //printf("%d %d \n",itrA->val,carry);
            itrA->val=(itrA->val+itrB->val+carry)%10;
            carry=(prevAV+itrB->val+carry)/10;
            //printf("%d %d \n",itrA->val,carry);
        }
        else
        {
            itrB->val=(itrA->val+itrB->val+carry)%10; 
            carry=(itrA->val+prevBV+carry)/10;
        }
        
        
        prevA=itrA;
        prevB=itrB;
        itrA=itrA->next;
        itrB=itrB->next;
        //count++;
        //printf("%d \n",count);
    }
    
    if(gLength==1)
    {
        if(listLength(A)==listLength(B))
        {
            if(carry>0)
            {
                listnode *C = malloc(sizeof(listnode));
                C->val=carry;
                C->next=NULL;
                prevA->next=C;
                return A;
            }
            else
            {
                return A;
            }
            
        }
        else
        {
            while(itrA!=NULL)
            {
                prevAV=itrA->val;
                itrA->val=(itrA->val+carry)%10;
                carry=(prevAV+carry)/10;
                prevA=itrA;
                itrA=itrA->next;
            }
            // check if need extra space
            if(carry>0)
            {
                listnode *C = malloc(sizeof(listnode));
                C->val=carry;
                C->next=NULL;
                prevA->next=C; 
                return A;
                
            }
            else
            {
                return A;
            }
        }
    }
    else
    {
            while(itrB!=NULL)
            {
                prevBV=itrB->val;
                itrB->val=(itrB->val+carry)%10;
                carry=(carry+prevBV)/10;
                prevB=itrB;
                itrB=itrB->next;
            }
            // check if need extra space
            if(carry>0)
            {
                listnode *C = malloc(sizeof(listnode));
                C->val=carry;
                C->next=NULL;
                prevB->next=C;
                return B;
            }
            else
            {
                return B;
            }
        
    }
    
}
