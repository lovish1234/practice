int Solution::maxp3(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // a represnts the case where two numbers are negetive and one positive
    // b represents the case where all the three numbers are positive
    sort(A.begin(),A.end());
    int a, b, ans, size=A.size();
    return ans= (a=A[0]*A[1]*A[size-1])>(b=A[size-3]*A[size-2]*A[size-1])?a:b;
}

