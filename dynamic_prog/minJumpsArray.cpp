int Solution::jump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size = A.size();
    int minArray[size];
    
    // it will take 0 jumps from last to last element
    minArray[size-1]=0;
    for(int i=0;i<size-1;i++)
    {
        minArray[i]=-1;
    }
    
    // i have to fill the minArray
    int tempMin;
    for(int i=(size-2);i>=0;i--)
    {
        for(int j=1;j<=A[i];j++)
        {
            if(i+j<=(size-1) && minArray[i+j]!=(-1) )
            {
                tempMin=minArray[i+j]+1;
                if(minArray[i]>tempMin || minArray[i]<0)
                {
                    minArray[i]=tempMin;
                }
            }
        }
    }
    
    return minArray[0];
}
