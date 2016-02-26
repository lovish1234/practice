vector<string> Solution::prefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map <string, int> M;
    for(int i=0;i<A.size();i++)
    {
        int s = A[i].size();
        for(int j=1;j<=s;j++)
        {
            string key= A[i].substr(0,j);
            if(M.find(key)!=M.end())
            {
                M[key]=M[key]+1;
            }
            else
            {
                M[key]=1;
            }
        }
    }
    
    vector<string> result;
    for(int i=0;i<A.size();i++)
    {
        int s=A[i].size();
        for(int j=1;j<=s;j++)
        {
            string key=A[i].substr(0,j);
            if(M[key]==1)
            {
                result.push_back(key);
                break;
            }
        }
        
    }
    
    return result;
}
