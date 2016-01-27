int Solution::diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size()==1 || A.size()==0)
    {
        return 0;
    }
    
    unordered_map<int,int> H;
    int i;
    for(i=0;i<A.size();i++)
    {
        if(H.find(A[i]+B)==H.end())
        {
            H[A[i]+B]=i;
        }
    }
    
    for(i=0;i<A.size();i++)
    {
        if( H.find(A[i])!=H.end() && H[A[i]]!=i)
        {
            return 1;
        }
    }
    return 0;
    
}
