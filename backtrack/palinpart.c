int IsPalin(string S)
{
    int size= S.length();
    for(int i=0; i<=size-1; i++)
    {
        if(S[i]!=S[size-1-i])
        {
            return 0;
        }
    }
    return 1;
}


void getSets(string S, vector< string > &temp, vector< vector < string > > &result)
{
    // if all the characters in the string are taken into consideration
    if(S.length()==0)
    {
        result.push_back(temp);
    }
    int flag;
    for(int i=1;i<=S.length();i++)
    {
        int flag=IsPalin(S.substr(0,i));
        if(flag)
        {
            temp.push_back(S.substr(0,i));
            getSets(S.substr(i), temp, result);
            temp.pop_back();
        }
    }
    
}


vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    vector <vector <string> > result;
    vector < string > temp;
    
    if(A.size()<=1)
    {
        temp.push_back(A);
        result.push_back(temp);
        return result;
    }
    getSets(A, temp, result);
    return result;
}
