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

int listLength(listnode* A)
{
    int count=0;
    listnode* itr=A;
    while(itr!=NULL)
    {
        count++;
        itr=itr->next;
    }
    return count;
}
listnode* getIntersectionNode(listnode* A, listnode* B) {
    
    listnode *temp;
    int A_length=listLength(A);
    int B_length=listLength(B);
    int init_walk= (A_length>B_length)?(A_length-B_length):(B_length-A_length);
    if(B_length>A_length)
    {
        temp=A;
        A=B;
        B=temp;
    }
    listnode *itrA=A;
    listnode *itrB=B;
    int i;
    //printf("%d\n",init_walk);
    for(i=0;i<init_walk;i++)
    {
        itrA=itrA->next;
    }
    // 0 means the list a sublist of whole list
    while((itrA)!=NULL)
    {
        //printf("%d %d\n",itrA->val,itrB->val);
        if((itrA)==(itrB))
        {
            return itrA;
        }
            
        itrB=itrB->next;  
        itrA=itrA->next;
    }
    return NULL;
}
