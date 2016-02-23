/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* findNode(TreeNode* A)
{
    if(A->left==NULL)
    {
        return NULL;
    }
    else 
    {
        TreeNode* A_left=A->left;
        TreeNode* answer=A_left;
        while((answer->right)!=NULL)
        {
            answer=answer->right;
        }
        return answer;
    }
    
}
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
    {
        return NULL;
    }
    else 
    {
        TreeNode* node= findNode(A);
        //cout << node->val<< "\n";
        if(node!=NULL)
        {
            node->right=A->right;
            A->right=A->left;
            A->left=NULL;
            //cout << A->right->val << "\n";
            A->right=flatten(A->right);
        }
        else
        {
            //cout << A->right->val;
            A->right=flatten(A->right);
        }
        return A;
    }
    
}
