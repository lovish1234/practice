/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void pathSumAlt(TreeNode* root, int sum, vector<int>& temp, vector< vector < int> >& result)
{
    if(root==NULL)
    {
        return ;
    }
    

    
    if(root->left==NULL && root->right==NULL)
    {
        if(sum-(root->val)==0)
        {
            temp.push_back(root->val);
            result.push_back(temp);
            temp.pop_back();
        }
        else
        {
            return ;
        }
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        temp.push_back(root->val);
        pathSumAlt(root->right,sum-(root->val), temp, result);
        temp.pop_back();
        
    }
    else if(root->left!=NULL && root->right==NULL)
    {
        temp.push_back(root->val);
        pathSumAlt(root->left,sum-(root->val), temp, result);
        temp.pop_back();
    }
    else if(root->left!=NULL && root->right!=NULL)
    {
        temp.push_back(root->val);
        pathSumAlt(root->left,sum-(root->val), temp, result);
        pathSumAlt(root->right,sum-(root->val), temp, result);
        temp.pop_back();
    }
    
 
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> temp;
    vector< vector <int> > result;
    pathSumAlt(root, sum, temp, result);
    
    return result;
}
