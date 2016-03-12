#define MAXINPUT 53

int numTreesAlt(int A, int*X)
{
    int answer=0;
    if(X[A]!=-1)
    {
        return X[A];
    }
    else
    {
        for(int i=0;i<A;i++)
        {
            answer+=numTreesAlt(i,X)*numTreesAlt(A-1-i,X);
        }
        X[A]=answer;
        return answer;
    }
}

int Solution::numTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int *X=(int*)malloc(sizeof(int)*(MAXINPUT));
    for(int i=0;i<MAXINPUT;i++)
    {
        X[i]=-1;
    }
    X[0]=1;
    X[1]=1;    
    return numTreesAlt(A, X);
}

