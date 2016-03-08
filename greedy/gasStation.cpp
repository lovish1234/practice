

int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // starting and returning to 0
    int size=gas.size();
    if(size==0)
    {
        return 0;
    }
    int sum[2*size-1], totalSum=0,it=0;
    for(int i=0;i<size;i++)
    {
        sum[i]=gas[i]-cost[i];
        totalSum+=sum[i];
    }
    
    if(totalSum<0)
    {
        return -1;
    }
    
    for(int i=size;i<2*size-1;i++)
    {
        sum[i]=gas[i-size]-cost[i-size];
    }
    
    int count=0,indexSum=0;
    for(int i=0;i<2*size-1;i++)
    {
        indexSum+=sum[i];
        if(indexSum<0)
        {
            indexSum=0;
            count=0;
        }
        else
        {
            count++;
        }
        
        if(count==size)
        {
            return i-size+1;
        }
    }
    
}
