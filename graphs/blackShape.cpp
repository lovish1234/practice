void DFS( vector<string> &A, int i, int j, int** visited, int r, int c)
{
    if ( ( i<0 || i>(r-1) ) || ( (j<0) || j>(c-1) ) )
    {
        return;
    }
    
    if(A[i].substr(j,1).compare("O")==0 || visited[i][j]==1)
    {
        return;
    }
    
    // mark as visited
    visited[i][j]=1;
    
    DFS(A, i+1, j, visited, r, c);
    DFS(A, i-1, j, visited, r, c);
    DFS(A, i, j+1, visited, r, c);
    DFS(A, i, j-1, visited, r, c);

}


int Solution::black(vector<string> &A) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int row = A.size();
    int column = A[0].size();
    int answer=0;
    
    int **visited = (int**)malloc(sizeof(int*)*row);
    for(int i=0;i<row; i++)
    {
        visited[i]=(int*)malloc(sizeof(int)*column);
    }
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            visited[i][j]=0;
        }
    }
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            // if given character is equal to X and is not visited till now
            if( A[i].substr(j,1).compare("X")==0 && visited[i][j]==0 )
            {
                // DFS to mark the connected area as visited and update answer
                DFS(A, i, j, visited, row, column);
                answer+=1;
            }
        }

    }
    
    return answer;
    
}

