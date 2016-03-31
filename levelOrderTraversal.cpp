/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > answer;
    vector<int> level;
    
    TreeNode* temp;
    queue<TreeNode* > Q;
    
    
    
    
    vector<TreeNode*> currentLevel, nextLevel;
    if(A==NULL)
    {
        return answer;
    }
    
    if(A!=NULL)
    {
        currentLevel.push_back(A);
    }
    
    while(!currentLevel.empty())
    {
        for(int i=0; i<currentLevel.size();i++)
        {
            temp = currentLevel[i];
            level.push_back(temp->val);
            if(temp -> left!=NULL)
            {
                nextLevel.push_back(temp->left);
            }
            if(temp->right!=NULL)
            {
                nextLevel.push_back(temp->right);
            }
        }
        answer.push_back(level);
        level.clear();
        
        currentLevel.clear();
        currentLevel = nextLevel;
        nextLevel.clear();
        
    }

    return answer;
}
