unordered_map <string, int> H;

void init()
{
    if(!H.empty())
    {
        H.erase(H.begin(),H.end());
    }
}
int wordBreakAlt( string A, vector<string> &B)
{
    int stringSize=A.length();
    int size= B.size();
    int dictWordSize;
/*    
    if(H.find(A)!=H.end())
    {
        cout << "here" << " " << A << "\n";
        return H[A];
    }
    */
    
    
    // loop will run n times 
    for(int i=0;i<size;i++)
    {
        //O(sizeof B[i]) operation
        dictWordSize= B[i].length();
        //cout << B[i] << " " << A.substr(0, dictWordSize) << "\n";
        if(B[i].compare(A.substr(0, dictWordSize))==0)
        {
            //H[A.substr(0,dictWordSize)]=1;
            //cout << B[i] << " " << A.substr(0, dictWordSize) << "\n";
            A = A.substr(dictWordSize);
            //cout << A << "\n";
            if(A.empty()==1)
            {
                return 1;
            }
            else
            {
                //H[A]=wordBreakAlt(A, B);
                return wordBreakAlt(A,B);
            }
        }
    }
    //H[A]=0;
    return 0;
}

int Solution::wordBreak(string A, vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    init();
    return wordBreakAlt(A,B);
    /*
    for(auto it= H.begin();it!=H.end();++it)
    {
        cout << it->first << " " << it->second << "\n";
    }
    */
    
    
}
