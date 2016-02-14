/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxIndex(vector<int> &A)
{
    int max=0,i;
    for(i=0;i<A.size();i++)
    {
        if(i!=0)
        {
            if(A[i]>A[max])
            {
                max=i;
            }
        }
        else
        {
            if(A[i]>INT_MIN)
            {
                max=i;
            }
        }
    }
    return max;
}

TreeNode* buildTreeAlt(vector<int> &A, TreeNode* node) 
{
    if(A.size()==0)
    {
        return NULL;
    }
    if(A.size()==1)
    {
        node->val=A[0];
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    TreeNode* leftT=(TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* rightT=(TreeNode*)malloc(sizeof(TreeNode));
    int max= maxIndex(A);
    node->val=A[max];

    if(max!=0)
    {
        vector<int> A_left(A.begin(), A.begin()+max);
        node->left=buildTreeAlt(A_left,leftT);
    }
    else
    {
        node->left=NULL;
    }
    if(max!=(A.size()-1))
    {
        vector<int> A_right(A.begin()+max+1,A.end());
        node->right=buildTreeAlt(A_right,rightT);
    }
    else
    {
        node->right=NULL;
    }
    return node;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
    {
        return NULL;
    }
    TreeNode* node =(TreeNode*)malloc(sizeof(TreeNode));
    if(A.size()==1)
    {
        node->val=A[0];
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    return buildTreeAlt(A, node);
}

