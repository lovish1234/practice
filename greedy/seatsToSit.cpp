#define MOD 10000003



int Solution::seats(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> positions;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='x')
        {
            positions.push_back(i);
        }
    }
    int median=positions.size()/2;
    int left=0, right=0,temp1,temp2,temp3;
    for(int i=(median-1);i>=0;i--)
    {
        temp1=(positions[median]%MOD-positions[i]%MOD)%MOD;
        temp2=((median)%MOD-i%MOD)%MOD;
        temp3=(temp1%MOD-temp2%MOD)%MOD;
        left=(left%MOD+temp3%MOD)%MOD;
    }
    for(int i=(median+1);i<positions.size();i++)
    {
        temp1=(positions[i]%MOD-positions[median]%MOD)%MOD;
        temp2=((i)%MOD-median%MOD)%MOD;
        temp3=(temp1%MOD-temp2%MOD)%MOD;
        right=(right%MOD+temp3%MOD)%MOD;
    }
    
    return (left%MOD+right%MOD)%MOD;
    
}
