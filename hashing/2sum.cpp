vector<int> Solution::twoSum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> S=A;
    vector<int> result;

    int i,n=S.size(),tI_1=0,tI_2=0,I_1=0,I_2=0,maxI=INT_MAX,minI=INT_MAX,tMaxI,tMinI;
    if(n==0 || n==1)
    {
        return result;
    }
    
    map <int,int> H;
    //for first n entries, simple add to the hash table H
    for(i=0;i<n;i++)
    {
        if(H.find(S[i])==H.end())
        {
            H[S[i]]=i;
        }
        S.push_back(B-S[i]);
    }

    // for next n entries check if H[S[i]] exists, if yes 
    int k=S.size();
    
    /*
    printf("%d %d\n",n,k);
    for(i=0;i<k;i++)
    {
        printf("%d ",S[i]);
    }
    printf("\n");
    
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",S[i],H[S[i]]);
    }
    */
    
    
    for(i=n;i<k;i++)
    {
        if(H.find(S[i])!=H.end())
        {
            // As we cannot take one element more than one time, we need to check
            if(H[S[i]]!=(i-n))
            {
                //printf("%d %d\n",S[i],H[S[i]]);

                tI_1=H[S[i]];
                tI_2=(i-n);
                tMaxI=(tI_1>tI_2?tI_1:tI_2);
                tMinI=(tI_1>tI_2?tI_2:tI_1);
                if(maxI > tMaxI)
                {
                    I_1=tMinI;
                    I_2=tMaxI;
                    maxI=tMaxI;
                    minI=tMinI;
                }
                else if(maxI==tMaxI)
                {
                    if(minI > tMinI)
                    {
                        I_1=tMinI;
                        I_2=tMaxI;
                        maxI=tMaxI;
                        minI=tMinI;
                    }
                }
            }
        }
    }

    if(I_1==0 && I_2==0)
    {
        return result;
    }
    result.push_back(I_1+1);
    result.push_back(I_2+1);
    return result;
}
