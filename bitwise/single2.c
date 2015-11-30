/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
 
 

int power( int x, int n)
{
    int ans=1;
    int i;
    for(i=0;i<n;i++)
    {
        ans*=x;
    }
    return ans;
}

/*

int* decimalToBinary(int A, int sz)
{
    int i, bitArray[sz];
    for(i=0;i<sz;i++)
    {
        bitArray[i]=0;
    }
    
    i=0;
    while(A)
    {
        bitArray[i]=(A%2);
        i++;
        A/=2;
    }
    
    
    
    for(i=0;i<sz;i++)
    {
        printf("%d ",bitArray[i]);
    }
    printf("\n");
    

    return bitArray;
}

int binaryToDecimal(int *bitArray, int sz)
{
    int i,ans=0;
    for(i=0;i<sz;i++)
    {
        if(bitArray[i]==1)
        {
            ans+=power(2,i);
        }
    }
    return ans;
}

*/


int singleNumber(const int* A, int n1) 
{
    
    
    int j,bitArray[32],i,temp[32], tempvar,ans=0;
    for(i=0;i<32;i++)
    {
        bitArray[i]=0;
    }
    
    
   
    for(j=0;j<n1;j++)
    {
    
        for(i=0;i<32;i++)
        {
            temp[i]=0;
        }
        
        i=0;
        tempvar=A[j];
        while(tempvar)
        {
            temp[i]=(tempvar%2);
            i++;
            tempvar/=2;
        }
    
        for(i=0;i<32;i++)
        {
            if(temp[i]==1)
            {
                bitArray[i]+=1;
                if(bitArray[i]==3)
                {
                    bitArray[i]=0;
                }
            }
        }
    
    }
    
    /*
     for(i=0;i<32;i++)
    {
        printf("%d ",bitArray[i]);
    }
    */
    
    for(i=0;i<32;i++)
    {
        if(bitArray[i]==1)
        {
            ans+=power(2,i);
        }
    }
   

    
    return ans;
}
