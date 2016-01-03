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
int listLength(listnode *A)
{
    listnode *curr=A;
    int count=0;
    while(curr!=NULL)
    {
        curr=curr->next;
        count++;
    }
    return count;
}

listnode* firstNonDup(listnode* A)
{
        
    int length = listLength(A);
    // if list is empty or only has one element 
    if(length==0 || length==1)
    {
        return A;
    }
    listnode* curr=A;
    listnode* n=A->next;
    // if first element in list is a duplicate
    while(n->val==curr->val)
    {
        while(n->val==curr->val)
        {
            n=n->next;
         
            if(n==NULL)
            {
                //printf("Here\n");
                return NULL;
            }
        }
        curr=n;
        n=curr->next;
        if(n==NULL)
        {
            return curr;
        }

    }
    return curr;
}

listnode* deleteDuplicates(listnode* A) {
    
    listnode* head;
    listnode* result;
    listnode* resultPtr;
    listnode* n;
 

    
    
    head=firstNonDup(A);
    //printf("%d\n",head->val);
    if(head==NULL)
    {
        return NULL;
    }
    resultPtr=head;
    result=resultPtr;
    n=head->next;
    
    while(n!=NULL)
    {

        n=head->next;
        if(n==NULL)
        {
            return result;
        }
        head=firstNonDup(n);
        if(head==NULL)
        {
            resultPtr->next=NULL;
            return result;
        }
        resultPtr->next=head;
        resultPtr=resultPtr->next;
    }
    

    
    return result;
}

