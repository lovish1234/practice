/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// if all the elements of every list are finished return 0
int elementRemaining(vector<ListNode*> &A)
{
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=NULL)
        {
            return 1;
        }
    }
    return 0;
}

ListNode* minValue(vector<ListNode*> &A)
{
    int minVal=INT_MAX,minI;
    ListNode* ans;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=NULL)
        {
            if(A[i]->val < minVal)
            {
                minVal=A[i]->val;
                minI=i;
                ans=A[i];
            }
        }
    }
    A[minI]=A[minI]->next;
    return ans;
}
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* result= (ListNode*)malloc(sizeof(ListNode));
    ListNode* ans=result;
    while( elementRemaining(A))
    {
        result->val=(minValue(A))->val;
        result->next=(ListNode*)malloc(sizeof(ListNode));
        if(elementRemaining(A))
        {
            result=result->next;
        }
        else
        {
            result->next=NULL;
        }
    }
    return ans;
}
