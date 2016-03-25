int Solution::maximalRectangle(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int rowSize = A.size(), columnSize= A[0].size();
    int x_1, x_2, y_1, y_2;
    bool result[rowSize][columnSize][rowSize][columnSize];
    int ans=0;
    for(int i=0;i< rowSize; i++)
    {
        for(int j=0;j< columnSize; j++)
        {
            result[i][j][i][j]= A[i][j];
            if( result[i][j][i][j]==1)
            {
                //cout << i << " " << j << " " << i << " " << j << "\n" ;
                ans=1;
            }
        }
    }
    
    for(int i=0;i< rowSize; i++)
    {
        for(int k=i+1; k< rowSize; k++)
        {
            for(int j=0; j<columnSize; j++)
            {
                result[i][j][k][j]=result[i][j][k-1][j] && A[k][j];
                if( result[i][j][k][j]==1 && (k-i+1)>=ans)
                {
                    //cout << i << " " << j << " " << k << " " << j << "\n" ;
                    ans=(k-i+1);
                }    
            }
        }
    }
    
    for(int j=0; j<columnSize; j++)
    {
        for(int l=j+1; l<columnSize; l++)
        {
            for(int i=0; i<rowSize; i++)
            {
                result[i][j][i][l]=result[i][j][i][l-1] && A[i][l];
                if( result[i][j][i][l]==1 && (l-j+1)>=ans)
                {
                    //cout << i << " " << j << " " << i << " " << l << "\n" ;
                    ans=(l-j+1);
                }      
            }
        }
    }
    
    
    for(int i=0; i<  rowSize ; i++)
    {
        for(int k=i+1; k< rowSize; k++)
        {
            for(int j=0; j< columnSize; j++)
            {
                for(int l=j+1; l< columnSize; l++)
                {
                    result[i][j][k][l]= result[i][j][k-1][l-1] && result[i][l][k][l] && result[k][j][k][l];
                    if( result[i][j][k][l]==1 && (l-j+1)*(k-i+1)>=ans)
                    {
                        //cout << i << " " << j << " " << k << " " << l << "\n" ;
                        ans=(l-j+1)*(k-i+1);
                    }         
                }
            }
        }
    }
    
    return ans;
}

