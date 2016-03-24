int Solution::wordBreak(string A, vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size = A.size();
    int Bsize = B.size();
    unordered_map <string,int> dict;
    for(int i=0;i<Bsize;i++)
    {
        dict[B[i]]=1;
    }
    
    if (A.empty())
    {
        return false;
    }
    
    vector<bool> table(A.size(),false);
    for (int i=size-1;i>=0;i--) 
    {
        for (int j=i;j<size;j++) 
        {
            string temp(A.begin()+i,A.begin()+j+1);
            if (dict.find(temp) != dict.end()) 
            {
                if (j==size-1 || table[j+1]) 
                {
                    table[i] = true;
                    break;
                }
            }
        }
    }
    return table[0];
    
    
    /*
    vector<vector<bool> > table(size,vector<bool>(size,false));
    for (int i=0;i<size;i++)
    {
        for (int j=i;j<size;j++)
        {
            if (dict.find(A.substr(i,j-i+1))!=dict.end())
            {
                    table[i][j]=true;
            }
        }
    }
       
    for (int i=0;i<size;i++)
    {
        for (int j=i;j<size;j++)
        {
            for(int k=i;k<j;k++)
            {
                if (!table[i][j])
                {
                        table[i][j]=table[i][k]&&table[k+1][j];
                }
            }
        }
    }
    
    
    int i = 0;
    for (int j=i;j<size;j++)
    {
        for(int k=i;k<j;k++)
        {
            if (!table[i][j])
            {
                table[i][j]=table[i][k]&&table[k+1][j];
            }
        }
    }     
    return table[0][size-1];
    */
    
}
