vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> result;
    if(B > A.size())
    {
        return result;
    }
    
    unordered_map<int,int> M;
    
    for(int i=0;i<B;i++)
    {
        M[A[i]]=i;
    }
    result.push_back(M.size());
    /*
    if(M.find(A[0])!=M.end() && M[A[0]]==0)
    {
        M.erase(A[0]);
    }
    */
    
    for(int j=0;j<(A.size()-B);j++)
    {
 
        if(M.find(A[j])!=M.end() && M[A[j]]==j)
        {
            M.erase(A[j]);
        }
        M[A[B+j]]=(B+j);
        result.push_back(M.size());
    }
    return result;
}
