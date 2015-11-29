/**
 * @input x : Integer
 * @input n : Integer
 * @input d : Integer
 * 
 * @Output Integer
 */
 
long long int power( int x, int n)
{
    long long int ans=1;
    int i;
    for(i=0;i<n;i++)
    {
        ans*=x;
    }
    return ans;
}

int positive( int x, int d)
{
    while(x<0)
    {
        x+=d;
    }
    return x;
}
int powmod(int x, int n, int d) {
    
    if(d==1)
    {
        return 0;
    }
    int ans;
    if(x<0)
    {
        x=positive(x,d);
    }
    
    ans = (power(x,n)%d);
    return ans;
}

