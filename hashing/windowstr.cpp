string Solution::minWindow(string S, string T) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // H containes the number of instances needed for each character
    // M contains number of instances present in each character
    unordered_map < char , int> H;
    unordered_map < char , int> M;
    
    
    if (S.size()<T.size()){return "";}

    for(int i=0;i<T.size();i++){H[T[i]]++;}

    int minLength=INT_MAX;
    int startF;
    
    int start=0;
    int end=S.size()-1;
    
    while (H.find(S[start])==H.end()){if(start>=S.size()){return "";} start++;} //remove irralevent starting chars
    while (H.find(S[end])==H.end()){ if(end<0){return "";} end--;} // remove irralevent ending characters
    
    // number of instances of characters from start to end
    for(int i=start;i<=end;i++){ M[S[i]]++;}
    
    // if the number of instances are more than required or not in T
    while (M[S[end]]>H[S[end]] || H.find(S[end])==H.end())
    { 
        M[S[end]]--;
        end--;
    }
    
    
    
    for (int i=0;i<T.size();i++)
    {  // if no covered substring found, return ""
            if (M[T[i]]<H[T[i]]){return "";}
    }
     
    
    
    
    if (end-start+1<minLength){minLength=end-start+1; startF=start;} //store the result
         
         
        while (start<end)
        {
            if (end-start+1<minLength)
            {
                minLength=end-start+1; 
                startF=start;
                
            } //store the result
            
            if (H.find(S[start])==H.end())
            {
                start++;
                continue;
                
            } // if current char is not in T, go next
            
            if (M[S[start]]>H[S[start]])
            {
                M[S[start]]--;
                start++;
                continue;
                
            } // if more chars in this substring, go next
             
            end++; 
            
            while (end<S.size() && S[end]!=S[start])
            { 
                if (H[S[end]]>0)
                {
                    M[S[end]]++;
                    
                } 
                end++;
                
            } //move to find a substring covers T
            
            if (end>=S.size())
            {
                end=S.size()-1;
            }
            else
            {
                M[S[end]]++;
            }
             
            if (S[end]==S[start])
            { 
                M[S[start]]--; 
                if (M[S[start]]<H[S[start]])
                {
                    break;
                } 
                start++;
                continue;
            }        
            break;
        }
         
        return S.substr(startF,minLength);
    
    

}
