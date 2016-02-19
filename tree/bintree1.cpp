/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(inorder.size()==0)
    {
        return NULL;
    }
    TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
    node->val=postorder[postorder.size()-1];
    int i=0;
    for(i=0;i<inorder.size();i++)
    {
        if(inorder[i]==(node->val))
        {
            break;
        }
    }
    vector<int> linorder(inorder.begin(),inorder.begin()+i);
    vector<int> lpostorder(postorder.begin(),postorder.begin()+i);
    vector<int> rinorder(inorder.begin()+i+1,inorder.end());
    vector<int> rpostorder(postorder.begin()+i,postorder.end()-1);

    node->left=buildTree(linorder,lpostorder);
    node->right=buildTree(rinorder,rpostorder);
    return node;
}
