/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (preorder.size()==0)
    {
        return NULL;
    }
    TreeNode* node= (TreeNode*)malloc(sizeof(TreeNode));
    node->val=preorder[0];
    // find the index i for which preorder[0]==inorder[i], split both the arrays based on this
    int i,j;
    for(i=0;i<inorder.size();i++)
    {
        if(inorder[i]==preorder[0])
        {
            break;
        }
    }
    /*
    for(j=1;j<preorder.size();j++)
    {
        if(preorder[j]==inorder[i+1])
        {
            break;
        }
    }*/
    j=i+1;
    // 1 to j-1 of preorder is lpreorder
    vector<int> lpreorder(preorder.begin()+1,preorder.begin()+j);
    // 1 to i-1 of inorder is linorder
    vector<int> linorder(inorder.begin(),inorder.begin()+i);
    
    // j to end of preorder is rpreorder
    vector<int> rpreorder(preorder.begin()+j,preorder.end());

    // i+1 to end of inorder is rinorder
    vector<int> rinorder(inorder.begin()+i+1,inorder.end());

    node->left=buildTree(lpreorder,linorder);
    node->right=buildTree(rpreorder,rinorder);
    
    return node;
}
