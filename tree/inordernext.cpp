/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* findDataBST(TreeNode* A, int B)
{
    if(A==NULL)
    {
        return NULL;
    }
    if(A->val==B)
    {
        return A;
    }
    else if(A->val < B)
    {
        findDataBST(A->right,B);
    }
    else if(A->val > B)
    {
        findDataBST(A->left,B);
    }
}
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* current=findDataBST(A,B);
    if(current==NULL)
    {
        return NULL;
    }
    
    //Case 1: If the given node has a right subtree
    TreeNode* currRight=current ->right;
    if(currRight!=NULL)
    {
        // find the leftmost node in right subtree
        while(currRight->left!=NULL)
        {
            currRight=currRight->left;
        }
        return currRight;
    }
    
    //Case 2: If the given node does not have a right subtree, look for an ancestor with right subtree
    TreeNode* ancestor=A;
    TreeNode* successor=NULL;
    while(ancestor!=current)
    {
        if(current->val < ancestor->val)
        {
            successor=ancestor;
            ancestor=ancestor->left;
        }
        else
        {
            ancestor=ancestor->right;
        }
    }
    return successor;
}
