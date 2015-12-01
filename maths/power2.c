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

int isPower(int A) {
    
    if(A==0 || A==1 || IsPrime(A)==1)
    {
        return 0;
    }
    
    int i, numPrimes=0;
    for(i=2;i<=((A/2)+1);i++)
    {
        if(IsPrime(i)==1)
        {
            numPrimes++;
        }
        
    }
    int a[numPrimes], p[numPrimes],temp,j=0;
    //printf("%d\n",numPrimes);
    
    for(i=2;i<=(A/2)+1;i++)
    {
        if(IsPrime(i)==1)
        {
            temp=A;
            a[j]=i;
            p[j]=0;
            //printf("%d %d\n",i,a[j]);
            while(temp)
            {
                if(temp%i==0)
                {
                    
                    p[j]++;
                    temp/=i;
                }
                else
                {
                    j++;
                    break;
                }
            
            }
        }
    }
    
    
    /*
    for(j=0;j<numPrimes;j++)
    {
        printf("%d ",a[j]);
        
    }
    printf("\n");
    for(j=0;j<numPrimes;j++)
    {
        printf("%d ",p[j]);
        
    }
    printf("\n");
    */
    
    // An array has either 0 or a fixed value >1
    int value,count=0;
    for(j=0;j<numPrimes;j++)
    {
        if(p[j]==1)
        {
            return 0;
        }
        else if(p[j]==0)
        {
            continue;
        }
        else
        {
            if(count==0)
            {
                value=p[j];
                count++;
            }
            else
            {
                if(p[j]!=value)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
    
}
