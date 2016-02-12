/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
    {
        return 0;
    }
    if(A->left==NULL && A->right==NULL)
    {
        if(B-(A->val)==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(A->left==NULL && A->right!=NULL)
    {
        int rSum=hasPathSum(A->right,B-(A->val));
        return rSum;    
    }
    else if(A->left!=NULL && A->right==NULL)
    {
        int lSum=hasPathSum(A->left, B-(A->val));
        return lSum;
    }
    else if(A->left!=NULL && A->right!=NULL)
    {
        int lSum=hasPathSum(A->left, B-(A->val));
        int rSum=hasPathSum(A->right,B-(A->val));
        return (lSum || rSum);
    }

}
