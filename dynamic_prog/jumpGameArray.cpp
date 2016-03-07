#define MAX_INDEX 1000000
int X[MAX_INDEX];
void init()
{
    for(int i=0;i<MAX_INDEX;i++)
    {
        X[i]=0;
    }
}


int Solution::canJump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size= A.size();
    if(A[0]==0 && size!=1)
    {
        return 0;
    }
    else if(A[0]==0 && size==1)
    {
        return 1;
    }
    init();
    
    X[0]=1;
    for(int i=1;i<size;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            X[i]=((X[j]) && (A[j]>=(i-j)));
            if(X[i]==1)
            {
                break;
            }
        }
    }
    
    return X[size-1];
}
