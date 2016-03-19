
int Solution::maxcoin(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int size= A.size();
 
        if(size==2)
        {
            return max(A[0],A[1]);
        }
        vector<int> B(A.begin(),A.end()-2);
        vector<int> C(A.begin()+1,A.end()-1);
        vector<int> D(A.begin()+2,A.end());

        int subCase1 = maxcoin(B);
        int subCase2 = maxcoin(C);
        int subCase3 = maxcoin(D);
        
        int case1 = A[size-1]+min(subCase2,subCase1);
        int case2 = A[0]+min(subCase2,subCase3);

        //cout << case1 << case2 << case3 << case4 << "\n";
        return max(case1,case2);

}

