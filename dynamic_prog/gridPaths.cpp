/*
int getSets (int x, int y, vector< vector< int> > &A)
{
    int m = A.size();
    int n = A[0].size();
    
    if(x==(m-1) && y==(n-1))
    {
        return 1;
    }
    
    if(x<(m-1) && A[x+1][y]==0 && y<(n-1) && A[x][y+1]==0)
    {
        return (getSets(x+1,y,A) + getSets(x,y+1,A));
    }
    else if(x<(m-1) && A[x+1][y]==0 && (y>=(n-1) || A[x][y+1]==1))
    {
        return getSets(x+1,y,A);
    }
    else if(y<(n-1) && A[x][y+1]==0 && (x>=(m-1) || A[x+1][y]==1))
    {
        return getSets(x,y+1,A);
    }
    else if( (y>=(n-1) || A[x][y+1]==1) && (x>=(m-1) || A[x][y+1]==1))
    {
        return 0;
    }
}
*/


int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m=A.size(), n=A[0].size();
    /*
    
    if(A[m-1][n-1]==1)
    {
        return 0;
    }
    
    if(m==1 && n==1)
    {
        return 1;
    }
    else if(m!=1 && n==1)
    {
        return getSets(m-1,n,A);
    }
    else if(m==1 && n!=1)
    {
        return getSets(m,n-1,A);
    }
    else if(m!=1 && n!=1)
    {
        return getSets(m,n-1,A)+getSets(m-1,n,A);
    }
    */
    int ways[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==1)
            {
                ways[i][j]=0;
            }
            else 
            {
                if(i>=1 && j>=1)
                {
                    ways[i][j]=ways[i][j-1]+ways[i-1][j];
                }
                else if(i>=1 && j==0)
                {
                    ways[i][j]=ways[i-1][j];
                }
                else if(i==0 && j>=1)
                {
                    ways[i][j]=ways[i][j-1];
                }
                else if(i==0 && j==0)
                {
                    ways[i][j]=1;
                }
            }
        }
    }
    
    return ways[m-1][n-1];
}

