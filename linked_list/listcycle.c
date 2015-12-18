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

 
listnode* detectCycle(listnode* A) {
    listnode *tortoise=A;
    listnode *hare=A;
    int count=1,i=0;
    //listnode *meeting;
    listnode *cycleStart=A;
    while(hare!=NULL)
    {
        tortoise=tortoise->next;
        if(hare->next!=NULL)
        {
            hare=hare->next->next;
            if(hare==tortoise)
            {
                //printf("1\n");
                
                while(cycleStart!=tortoise)
                {
                    tortoise=tortoise->next;
                    cycleStart=cycleStart->next;
                    
                }
                
        
                return cycleStart;
            }
        }
        else
        {
            //no cycle
            return NULL;
        }
    }
    
    
    return NULL;
}
