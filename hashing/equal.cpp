bool lexCompare(vector<int> A, vector<int> B)
{
    if(A[0]<B[0])
    {
        return 1;
    }
    else if(A[0]>B[0])
    {
        return 0;
    }
    else
    {
        if(A[1]<B[1])
        {
            return 1;
        }
        else if(A[1]>B[1])
        {
            return 0;
        }
        else
        {
            if(A[2]<B[2])
            {
                return 1;
            }
            else if(A[2]>B[2])
            {
                return 0;
            }
            else
            {
                if(A[3]<B[3])
                {
                    return 1;
                }
                else if(A[3]>B[3])
                {
                    return 0;
                }
            }
        }
    }
}


vector<int> Solution::equal(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int length= A.size();
    unordered_map< int, pair<int,int> > H;
    vector<int> result;
    vector<int> temp_result;
    int flag=0;
    
    if(A.size()<4)
    {
        return result;
    }
    int a1,b1,c1,d1,temp;
    for(int i=0;i<length-1;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            if(H.find(A[i]+A[j])==H.end())
            {
                H[A[i]+A[j]]=make_pair(i,j);
            }
            else
            {
                a1=i,b1=j,c1=H[A[i]+A[j]].first,d1=H[A[i]+A[j]].second;
                result.resize(4);
                temp_result.resize(4);
                if(a1<c1 && b1!=d1 && b1!=c1)
                {
                    temp_result[0]=(a1);
                    temp_result[1]=(b1);
                    temp_result[2]=(c1);
                    temp_result[3]=(d1);
                    
                }
                else if(a1>c1 && b1!=d1 && d1!=a1)
                {
                    temp_result[0]=(c1);
                    temp_result[1]=(d1);
                    temp_result[2]=(a1);
                    temp_result[3]=(b1);                    
                }
                else
                {
                    continue;
                }

                if(flag==0)
                {
                    flag=1;
                    result[0]=temp_result[0];
                    result[1]=temp_result[1];
                    result[2]=temp_result[2];
                    result[3]=temp_result[3];
                }
                else if( lexCompare(temp_result,result))
                {
                    result[0]=temp_result[0];
                    result[1]=temp_result[1];
                    result[2]=temp_result[2];
                    result[3]=temp_result[3];
                }
    
            }
        }
    }
    return result;
}

