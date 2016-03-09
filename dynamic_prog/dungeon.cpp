int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m=A.size(),n=A[0].size();
    if(m==0 || n==0)
    {
        return 0;
    }
    int cost[m][n];
    
    cost[m-1][n-1]=max(0,0-A[m-1][n-1]);
    for(int i=(m-2);i>=0;i--)
    {
        cost[i][n-1]=max(0, cost[i+1][n-1]-A[i][n-1]);
    }
    for(int j=(n-2);j>=0;j--)
    {
        cost[m-1][j]=max(0, cost[m-1][j+1]-A[m-1][j]);
    }
    for(int i=(m-2);i>=0;i--)
    {
        for(int j=(n-2);j>=0;j--)
        {
            cost[i][j]=max(min(cost[i+1][j], cost[i][j+1])-A[i][j],0);
        }
    }
    return cost[0][0]+1;
}
