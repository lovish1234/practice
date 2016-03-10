int Solution::adjacent(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n= A[0].size(), prev_sum_excluding=0, prev_sum_including=max(A[0][0],A[1][0]), sum_excluding;
    for(int i=1;i<n;i++)
    {
        sum_excluding=max(prev_sum_including, prev_sum_excluding);
        prev_sum_including=prev_sum_excluding+max(A[0][i],A[1][i]);
        prev_sum_excluding=sum_excluding;

    }
    return max(prev_sum_including,prev_sum_excluding);
}
