int Solution::majorityElement(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    unordered_map <int, int> M;
    for(int i;i<A.size();i++)
    {
        if(M.find(A[i])!=M.end())
        {
            M[A[i]]++;
        }
        else
        {
            M[A[i]]=1;
        }
    }
    
    unordered_map<int, int> ::iterator it;
    int majority= floor(A.size()/2);
    for(it=M.begin();it!=M.end();++it)
    {
        if((*it).second > majority)
        {
            return (*it).first;
        }
    }
    

    
}

