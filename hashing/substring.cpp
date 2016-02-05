int Hash(string A)
{
    int ans=0;
    for(int i=0;i<A.length();i++)
    {
        ans+=(int)A[i];
    }
    return ans;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    //Two sets to store substrings and set of substrings 
    int m=B[0].length();
    int n=A.length();
    set <int> hsubs;
    set <string> subs;
    vector<int> result;
    
    if(m==0 || n<m)
    {
        return result;
    }
    
    //store the strings in set
    for(int i=0;i<B.size();i++)
    {
        subs.insert(B[i]);
        hsubs.insert(Hash(B[i]));
        //cout << B[i] << " " << Hash(B[i]) << "\n";
    }

    //cout << n << " " << m << "\n";
    int hs= Hash(A.substr(0,m));
    //cout << A.substr(0,m) << " " << hs << "\n";
    for(int i=1;i<(n-m+1);i++)
    {
        if(hsubs.find(hs)!=hsubs.end() && subs.find(A.substr(i-1,m))!=subs.end())
        {
            //cout << i-1 << "\n";
            result.push_back(i-1);
        }
        //cout << A[i-1] << " " << A[i+m-1] << "\n";
        //hs=Hash(A.substr(i,m));
        hs=hs-(int)A[i-1]+(int)A[i+m-1];
        //cout << A.substr(i,m)  << " " << hs << "\n";

    }
    
    return result;

}
