/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inorder(TreeNode* A, vector<int> &result)
{
    if(A==NULL)
    {
        return;
    }
    inorder(A->left, result);
    result.push_back(A->val);
    inorder(A->right, result);
}
int Solution::t2Sum(TreeNode* A, int B) {
    
    vector<int> result;
    inorder(A, result);
    //cout << result.size();
    if(result.size()<2)
    {
        return 0;
    }
    int i=0,j=result.size()-1;
    
    while(i<j)
    {
        if(result[i]+result[j]>B)
        {
            j--;
        }
        else if(result[i]+result[j]<B)
        {
            i++;
        }
        else if(result[i]+result[j]==B)
        {
            return 1;
        }
        
    }
    
    return 0;
    
}

