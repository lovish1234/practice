/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    // Do not wrtie main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> temp;
    vector< vector<int> > result;
    TreeNode* next;
    deque <TreeNode*> q;
    
    
    if(A==NULL)
    {
        return result;
    }
    
    q.push_back(A);
    TreeNode* X= new TreeNode(INT_MIN);
    q.push_back(X);
    
    
    int level=0;
    while(!q.empty())
    {
        next=q.front();

        if(next->val==INT_MIN && q.size()>1)
        {
            if(level%2==0)
            {
                result.push_back(temp);
            }
            else
            {
                reverse(temp.begin(),temp.end());
                result.push_back(temp);
            }
            temp.clear();
            q.pop_front();
            q.push_back(X);
            level++;
        }
        
        else if(next->val==INT_MIN && q.size()<=1)
        {
            q.pop_front();
        }
        else
        {
            temp.push_back(next->val);
            q.pop_front();
        }
    
        if(next->left!=NULL)
        {
            q.push_back(next->left);
        }
        if(next->right!=NULL)
        {
            q.push_back(next->right);
        }

        
    }

    if(temp.size()>0)
    {
        if(level%2==0)
        {
            result.push_back(temp);
        }
        else
        {
            reverse(temp.begin(),temp.end());
            result.push_back(temp);            
        }
    }
    
    
    
    
    return result;
}
