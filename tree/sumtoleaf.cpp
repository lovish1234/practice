/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define N 1003

int sumNumberAlt(TreeNode* A, int sum)
{
    sum=((sum*10)%N+(A->val)%1003)%N;
    //cout << sum << " ";
    if(A->left==NULL && A->right==NULL)
    {
        return sum;
    }
    else if(A->left!=NULL && A->right==NULL)
    {
        return sumNumberAlt(A->left,sum);
    }
    else if(A->left==NULL && A->right!=NULL)
    {
        return sumNumberAlt(A->right,sum);
    }
    else if(A->left!=NULL && A->right!=NULL)
    {
        return ((sumNumberAlt(A->right,sum)%N)+(sumNumberAlt(A->left,sum)%N))%N;
    }
    
}
int Solution::sumNumbers(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
    {
        return 0;
    }
    return sumNumberAlt(A,0);   
}
