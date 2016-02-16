/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// one way is to store path in a argument passed by reference and 
// returning a bool to convey if it exists or not
bool findPath(TreeNode *A, int val1, vector<TreeNode *> &path)
{
    if(A==NULL) return false;
    path.push_back(A);
    if((A->val)==val1)
    {
        return true;
    }
    
    if( (A->left && findPath(A->left,val1,path)) || (A->right && findPath(A->right,val1,path)) )
    {
        return true;
    }
    
    path.pop_back();
    return false;
}



int Solution::lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        // to store paths to n1 and n2 from the root
    vector< TreeNode* > path1,path2;
    int i;

    if(!findPath(A,val1,path1) || !findPath(A,val2,path2))
    {
        return -1;
    }
    
    for(i=0;i< path1.size() && i< path2.size();i++)
    {
        if(path1[i]->val!=path2[i]->val)
        {
            break;
        }
    }
    return path1[i-1]->val;
}
