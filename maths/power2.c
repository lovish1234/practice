/**
 * @input A : Integer
 * 
 * @Output Integer 0 / 1. 0 if false, 1 if true. 
 */
 

int IsPrime(int i)
{
    int j;
    for (j=2;j<=sqrt(i);j++)
    {
        //printf("%d %d",i,j);
        if(i%j==0)
        {
            //printf("B");
            return 0;
        }
    }
    return 1;
}

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


int isPower(int A) {
    
    if(A==1)
    {
        return 1;
    }
    
    if(A==0  || IsPrime(A)==1)
    {
        return 0;
    }
    
    
    long long int temp =0,i,j;
    
    for(i=2;i<32;i++)
    {
        for(j=2;j<=power(2,(32/i));j++)
        {
            if(power(j,i)==A)
            {
                return 1;
            }
        }
    }
    
    return 0;
}
