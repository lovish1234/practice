/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxSubArray(const int* A, int n1) {
    int i,j,sum=0,maxsum=-100000000,negetive;;
    
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
    // if the array is all negetive, select the least negetive number and return it
    // Line 1 ( Corresponds to arg 1 ) : An integer array. First number is the size S of the array. Then S numbers follow which indicate the elements in the array.

    // take two iterators i and j. whenever i is on a negetive number move it one point
    // to the right. 
    maxsum=0;
    
    for (i=0; i<n1; i++)
    {
        while (A[i] < 0)
        {
            i++;
        }
        for(j=i;j<n1;j++)
        {
            sum+=A[j];
            //printf("%d ",sum);
            if ( sum > maxsum )
            {
                maxsum = sum;
            }
            
        }
        
        
        
    }
    
    return maxsum;
}
