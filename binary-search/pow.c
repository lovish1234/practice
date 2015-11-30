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
    long long int ans=1;
    //long long int mult1=0;
    
    x=positive(x,d);
    x = x%d;
    long long int mult2=x;
    //printf("%d %lli\n",x,mult2);



    while (n>0)
    {
        if(n%2==1)
        {
            //mult1=ans*x;
            ans = (ans*mult2)%d;
        }
        n=n>>1;
        mult2=(mult2*mult2)%d;
        //printf("%d %d %d %lli %lli\n",ans,x,n,mult1,mult2);
        //x=(mult2)%d;
        
    }


    
    return (int) (ans%d);
    
}
