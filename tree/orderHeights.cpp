vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector< pair< int, int > > P;
    vector<int> result(heights.size());
    
    for(int i=0;i< heights.size(); i++)
    {
        P.push_back(make_pair(heights[i], infronts[i]));
        result[i]=-1;
    }
    sort(P.begin(), P.end());
    
    int k;
    for(int i=0;i< heights.size();i++)
    {
        k=0;
        for(int j=0;j<heights.size();j++)
        {

            if(result[j]==-1 && k==P[i].second)
            {
                result[j]=P[i].first;
                //cout << j << " " << P[i].first << "\n";
                break;
            }
            else if(result[j]==-1 && k<P[i].second)
            {
                //cout << j << " " << P[i].first << " " << P[i].second << "\n";
                k++;
            }
        }
    }
    
    return result;
}
