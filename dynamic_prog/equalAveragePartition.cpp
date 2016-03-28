vector<vector<vector<bool> > > table;
vector<int> result;
vector<int> real;


bool isPossible( int index, int sum, int length, int size)
{
    if(length==0)
    {
        return (sum==0);
    }

    if(index >=size)
    {
        return false;
    }

    if( table[index][sum][length]==false)
    {
        return false;
    }
    if( sum >= real[index])
    {
        result.push_back(real[index]);
        if( isPossible(index+1, sum-real[index], length-1, size))
        {
            return true;
        }
        result.pop_back();
    }
    
    if( isPossible(index+1, sum, length, size))
    {
        return true;
    }
    
    return table[index][sum][length]=false;
}

vector<vector<int> > Solution::avgset(vector<int> &A) {
    sort(A.begin(),A.end());
    int size= A.size();
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=A[i];
    }
    float ratio= (float)sum/size;
    
    real.clear();
    result.clear();
    table.clear();
    real = A;
    
    table.resize(real.size(), vector<vector<bool> > ( sum+1, vector<bool> (size, true)));
    
    // we want to stop before size as we dont want all the elements to go in one set, untimately we
    // want to partition the set into two non-empty sets
    for( int i=1; i< size; i++)
    {
        // number of elements in the set S must be integer
        if(((sum*i)%size)!=0)
        {
            continue;
        }
        
        int sumS1 = ((sum*i)/size);
        if( isPossible(0, sumS1, i, size) )
        {
            // find out the elements in array A which are not in result and return it as answer
            int ptr1 = 0, ptr2 = 0;
            vector<int> resultP1 = result;
            vector<int> resultP2;
            
            while( ptr1 < A.size() || ptr2 < result.size())
            {
                if(ptr2 < result.size() && result[ptr2]==A[ptr1])
                {
                    ptr1++;
                    ptr2++;
                    continue;
                }
                resultP2.push_back(A[ptr1]);
                ptr1++;
            }
        
            vector<vector<int> > answer;
            answer.push_back(resultP1);
            answer.push_back(resultP2);
            return answer;
        }
    }
    vector<vector<int> > answer;
    return answer;
    
}
