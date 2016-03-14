/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int maxPathAlt(TreeNode* A, int& maxIncRoot)
{
    if(A==NULL) return 0;   
    int sumC = A->val;
    int sumLC = maxPathAlt(A->left, maxIncRoot);
    int sumCR = maxPathAlt(A->right, maxIncRoot);
    
    if(sumLC>0)
    {
        sumC+=sumLC;
    }
    if(sumCR>0)
    {
        sumC+=sumCR;
    }
    
    maxIncRoot=max(maxIncRoot, sumC);
    return(max(A->val+sumLC,A->val+sumCR));
}
int Solution::maxPathSum(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int maxIncRoot= INT_MIN;
    int maxEndAtRoot= maxPathAlt(A, maxIncRoot);
    return max(maxIncRoot, maxEndAtRoot);

}
