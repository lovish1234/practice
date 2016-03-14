int min3(int a, int b, int c)
{
    return a>b?((b>c)?c:b):((a>c)?c:a);
}

int Solution::minDistance(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lenA= A.length();
    int lenB= B.length();
    if(lenA==0)
    {
        return lenB;
    }
    else if(lenB==0)
    {
        return lenA;
    }
    int array[lenA+1][lenB+1];
    
    // building one string from an empty string
    for(int i=0;i<lenA+1;i++)
    {
        array[i][0]=i;
    }
    for(int i=0;i<lenB+1;i++)
    {
        array[0][i]=i;
    }
    
    // accounting for deletion, insertion and substritution of characters in the string
    for(int i=1;i<lenA+1;i++)
    {
        for(int j=1;j<lenB+1;j++)
        {
            string sA= A.substr(i-1,1);
            string sB= B.substr(j-1,1);
            if(sA.compare(sB)==0)
            {
                array[i][j]=array[i-1][j-1];
            }
            else
            {
                array[i][j]=min3(array[i-1][j]+1,array[i][j-1]+1,array[i-1][j-1]+1);

            }
        }
    }

    
    return array[lenA][lenB];
}
