int Solution::candy(vector<int> &ratings) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int total=0, size=ratings.size();
    vector<int> left, right;
    left.push_back(1);
    right.push_back(1);
    
    for(int i=1;i<size;i++)
    {
        if(ratings[i]>ratings[i-1])
        {
            left.push_back(left[i-1]+1);
        }
        else
        {
            left.push_back(1);
        }
        
        if(ratings[size-i-1]>ratings[size-i])
        {
            right.push_back(right[i-1]+1);
        }
        else
        {
            right.push_back(1);
        }
    
    }
    reverse(right.begin(),right.end());
    for(int i=0;i<size;i++)
    {
        cout << left[i] << " " << right[i] << "\n";
        total+=max(left[i],right[i]);
    }
  
    return total;
}
