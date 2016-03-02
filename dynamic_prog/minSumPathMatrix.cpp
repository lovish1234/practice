int Solution::minPathSum(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int cost[A.size()][A[0].size()];
    
    // The last row would get added to every sum
    cost[0][0]=A[0][0];
    for(int i=1;i<A.size();i++)
    {
        cost[i][0]=cost[i-1][0]+A[i][0];
    }
    for(int j=1;j<A[0].size();j++)
    {
        cost[0][j]=cost[0][j-1]+A[0][j];
    }
    
    
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[0].size();j++)
        {
            cost[i][j]=A[i][j]+min(cost[i-1][j],cost[i][j-1]);
        }
    }
    return cost[A.size()-1][A[0].size()-1];
}

