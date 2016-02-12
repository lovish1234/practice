/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inOrderTraversal(TreeNode* A, vector <int> &result)
{
    if(A==NULL)
    {
        return;
    }
    else
    {
        
        inOrderTraversal(A->left, result);
        result.push_back(A->val);
        inOrderTraversal(A->right, result);

    }
}

int Solution::kthsmallest(TreeNode* root, int k) {
    vector<int> result;
    
    inOrderTraversal(root, result);
    
    return result[k-1];
    
    
}
