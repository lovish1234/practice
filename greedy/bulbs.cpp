int firstBulb( vector<int> &A)
{
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)
        {
            return i;
        }
    }
    return -1;
}

void changeState(vector<int> &A, int i)
{
    for(int j=i;j<A.size();j++)
    {
        if(A[j]==0)
        {
            A[j]=1;
        }
        else
        {
            A[j]=0;
        }
    }
}

int Solution::bulbs(vector<int> &A) {
    int ans=0, turnOn= firstBulb(A);
    while(turnOn!=-1)
    {
        changeState(A, turnOn);
        turnOn = firstBulb(A);    
        ans++;
    }
    return ans;
}

