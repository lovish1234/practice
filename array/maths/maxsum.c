/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxSubArray(const int* A, int n1) {
    int i,j,sum=0,maxsum=-100000000,negetive;;
    
    // If the whole array is negetive return the highest value
    for (i=0; i<n1; i++)
    {
        if (A[i]<0)
        {
            negetive+=1;
        }
        if (A[i] > maxsum)
        {
            maxsum=A[i];
        }
    }
    
    if(negetive==n1)
    {
        return maxsum;
    }
    
    for(i=0;i<n1;i++)
    {
        sum+=A[i];
        if(sum > 0 )
        {
            if ( sum > maxsum )
            {
                maxsum = sum;
            }
            
        }
        else
        {
            sum=0;
        }
    }
  
    
    return maxsum;
}
