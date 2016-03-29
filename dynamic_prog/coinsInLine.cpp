
int maxCoinAlt(vector<int> &A, int **array, int i, int j) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(array[i][j]!=0)
    {
        return array[i][j];
    }
    else
    {
        if(i==j)
        {
            array[i][j]=A[i];
            return array[i][j];
        }
        
        if(i+1==j)
        {
            array[i][j]=max(A[i],A[i+1]);
            return array[i][j];
        }
        
        int subCase1 = maxCoinAlt(A, array, i, j-2);
        int subCase2 = maxCoinAlt(A, array, i+1, j-1);
        int subCase3 = maxCoinAlt(A, array, i+2, j);
        
        int case1 = A[j]+min(subCase2,subCase1);
        int case2 = A[i]+min(subCase2,subCase3);
        array[i][j]=max(case1,case2);
        return array[i][j];
    }

}


int Solution::maxcoin(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size=A.size();
    int **array=(int**)malloc(size*sizeof(int*));
    for(int i=0;i<size;i++)
    {
        array[i]=(int*)malloc(size*sizeof(int));
    }
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            array[i][j]=0;
        }
    }
  
    return maxCoinAlt(A,array,0,size-1);

}
