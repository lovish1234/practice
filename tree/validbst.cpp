/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void preOrder(TreeNode* A, vector<int> &R)
{
    if(A==NULL)
    {
        return;
    }
    preOrder(A->left,R);
    R.push_back(A->val);
    preOrder(A->right,R);
    
}
 
int Solution::isValidBST(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*
    if(A==NULL) return 1;
    else if(A->left==NULL && A->right==NULL) return 1;
    else if(A->left==NULL) return (A->right->val > A->val) && isValidBST(A->right);
    else if(A->right==NULL) return (A->left->val < A->val) && isValidBST(A->left);
    else
    {
        return ((A->right->val > A->val) && (A->left->val < A->val) && isValidBST(A->right) && isValidBST(A->left));
    }*/
    
    vector<int> R;
    preOrder(A,R);
    for(int i=0;i<R.size()-1;++i)
    {
        if(R[i+1]<=R[i])
        {
            return 0;
        }
    }
    return 1;
}
