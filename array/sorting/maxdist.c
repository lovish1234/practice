/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maximumGap(const int* A, int n1) {
    
    int i,j,k,maxValue=0;
    int *B=(int*)malloc(sizeof(int)*n1);
    
    for(i=0;i<n1;i++)
    {
        B[i]=A[i];
    }
    
    for(i=0;i<n1-1;i++)
    {
        for(j=i;j<n1;j++)
        {
            if(A[j]>=A[i])
            {
               k=j-i;
               if(maxValue < k)
               {
                   maxValue = k;
               }
            }
        }
    }
    return maxValue;
}
