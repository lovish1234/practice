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
    int count=0;
    listnode* itrA=A;
    while(itrA!=NULL)
    {
        itrA=itrA->next;
        count++;
    }
    return count;
}

listnode* rotateRight(listnode* A, int B) {
    int A_length = listLength(A);
    if(A_length==1 || B==0 || (B%A_length)==0 || A_length==0)
    {
        return A;
    }
    
    //printf("%d\n",A_length);
    
    B=B%A_length;
    
    listnode* rindex=A;
    listnode* endindex=A;
    listnode* result;
    int i;
    for(i=0;i<A_length-1;i++)
    {
        endindex=endindex->next;
    }
    //printf("%d\n",endindex->val);
 

    for(i=0;i<A_length-B-1;i++)
    {
        rindex=rindex->next;
    }
    //printf("%d\n",rindex->val);
    result=rindex->next;
    
    rindex->next=NULL;
    endindex->next=A;
    
    return result;
}

