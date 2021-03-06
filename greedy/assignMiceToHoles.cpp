int Solution::mice(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int max, maxDiff=INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        max=abs(A[i]-B[i]);
        if(max > maxDiff)
        {
            maxDiff=max;
        }
    }
    return maxDiff;
}
