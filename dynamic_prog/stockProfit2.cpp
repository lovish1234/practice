int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size=A.size();
    if(size==1 || size==0)
    {
        return 0;
    }
    int min=A[0], maxProfit=0;
    for(int i=1;i<size;i++)
    {
        if(A[i]<min)
        {
            min=A[i];
        }
        if((A[i]-min)>0)
        {
            
            maxProfit+=(A[i]-min);
            //cout << maxProfit << "\n";
            min=A[i];    
        }
    }
    return maxProfit;
}
