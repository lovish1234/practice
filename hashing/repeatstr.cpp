int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    unordered_map <char, int > H;
    int i,length=0,maxlength=0,begin=0,end,maxbegin,maxend;
    for(i=0;i<A.length();i++)
    {
        if(H.find(A[i])==H.end())
        {
            H[A[i]]=i;
            end=i;
            length=end-begin+1;
        }
        else
        {
            begin=begin>(H[A[i]]+1)?begin:(H[A[i]]+1);
            end=i;
            length=end-begin+1;
            H[A[i]]=i;
        }
        if(length>maxlength)
        {
            maxbegin=begin;
            maxend=end;
            maxlength=length;
        }
    }
    return maxlength;
}
