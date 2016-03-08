int max3(int a, int b, int c)
{
    return (a>b)?((a>c)?a:c):((b>c)?b:c);
}

int min3(int a, int b, int c)
{
    return (a>b)?((b>c)?c:b):((a>c)?c:a);
}

int Solution::maxProduct(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size= A.size();
    
    int max_till=A[0], min_till=A[0], maxProduct=max_till, prev_max_till, prev_min_till;
    for(int i=1;i<size;i++)
    {
        prev_max_till= max_till, prev_min_till= min_till;
        max_till= max3(A[i], A[i]*prev_max_till, A[i]*prev_min_till);
        min_till= min3(A[i], A[i]*prev_max_till, A[i]*prev_min_till);
        maxProduct= max(max_till, maxProduct);
    }
    return maxProduct;
}
