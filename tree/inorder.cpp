/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<TreeNode*> S;
    vector<int> result;
    while(S.empty()==0 || A!=NULL)
    {
        if(A!=NULL)
        {
            S.push(A);
            A=A->left;
        }
        else
        {
            A=S.top();
            S.pop();
            result.push_back(A->val);
            A=A->right;
        }
    }
    return result;
}
