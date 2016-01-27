vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i;
    string word;
    unordered_map < string, vector<int> > H;
    vector< vector<int> > result;
    
    for(i=0;i<A.size();i++)
    {
        word=A[i];
        sort(word.begin(),word.end());
        if(H.find(word)==H.end())
        {
            vector<int> v;
            v.push_back(i+1);
            H.insert(make_pair(word,v));
        }
        else
        {
            H[word].push_back(i+1);
        }
    }
    
    
    for(unordered_map<string, vector<int> >::iterator iter = H.begin();iter!=H.end();iter++)
    {
        result.push_back((*iter).second);
    }
    
    

    return result;
    
}
