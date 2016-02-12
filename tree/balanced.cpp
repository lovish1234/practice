/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int heightTree(TreeNode* A)
{
    if(A==NULL) return -1;
    else
    {
        int hLeft=heightTree(A->left);
        int hRight=heightTree(A->right);
        return (hLeft>hRight)?hLeft+1:hRight+1;
    }
}
int Solution::isBalanced(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL) return 1;
    else
    {
        int hLeft=heightTree(A->left);
        int hRight=heightTree(A->right);
        return (isBalanced(A->left) && isBalanced(A->right) && abs(heightTree(A->left)-heightTree(A->right))<=1);
    }
}
