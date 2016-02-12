/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#define MAX 10000000
int preArray[MAX];
int postArray[MAX];
int i;

int isSameTree(TreeNode* A, TreeNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL && B==NULL)
    {
        return 1;
    }
    if((A==NULL && B!=NULL) || (A!=NULL && B==NULL))
    {
        return 0;
    }
    if(A->val==B->val)
    {
        return  (1 && (isSameTree(A->left,B->left) && isSameTree(A->right,B->right)));
    }
    else
    {
        return 0;
    }
}

TreeNode* constructTree(TreeNode* A)
{
    
    if(A==NULL)
    {
        return NULL;
    }
    else
    {
        TreeNode* B= (TreeNode*)malloc(sizeof(TreeNode));
        B->val=A->val;
        B->left = constructTree(A->right);
        B->right = constructTree(A->left);
        return B;

    }
}


void preOrderTraversal(TreeNode* A)
{
    if(A==NULL)
    {
        preArray[i]=-1;
        i++;
    }
    else
    {
        preOrderTraversal(A->left);
        i++;
        preArray[i]=A->val;
        i++;
        preOrderTraversal(A->right);
        i++;
    }
}

void postOrderTraversal(TreeNode* A)
{
    if(A==NULL)
    {
        postArray[i]=-1;
        i++;
    }
    else
    {
        postOrderTraversal(A->right);
        i++;
        postArray[i]=A->val;
        i++;
        postOrderTraversal(A->left);
        i++;
    }
}

void init()
{
    int i=0;
}



int isSymmetricTwo(TreeNode* A, TreeNode* B)
{
    if(A==NULL || B==NULL)
    {
        return (A==NULL)&&(B==NULL);
    }
    else
    {
        return (((A->val)==(B->val)) && isSymmetricTwo(A->left,B->right) && isSymmetricTwo(A->right, B->left));
    }
}

int Solution::isSymmetric(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if (!A)
    {
        return 1;
    }

    return isSymmetricTwo(A->left, A->right);
}

