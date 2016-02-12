/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details    
    TreeNode* lTree;
    TreeNode* rTree;
    if(A==NULL) return 0;
    else
    {
        lTree=A->left;
        rTree=A->right;
        if(lTree!=NULL && rTree==NULL)
        {
            return minDepth(lTree)+1;
        }
        else if(lTree==NULL && rTree!=NULL)
        {
            return minDepth(rTree)+1;
        }
        else if (lTree!=NULL && rTree!=NULL)
        {
            int lTreeDepth=minDepth(lTree);
            int rTreeDepth=minDepth(rTree);
        
            return (lTreeDepth<rTreeDepth)?(lTreeDepth+1):(rTreeDepth+1);
        }
        else if(lTree==NULL && rTree==NULL)
        {
            return 1 ;
        }
    }
}
