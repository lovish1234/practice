/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maximumGap(const int* A, int n1) {
    
    int i=0,j=n1-1,k,maxValue=0;
    int *B=(int*)malloc(sizeof(int)*n1);
    
    for(i=0;i<n1;i++)
    {
        B[i]=A[i];
    }
    
    int Rmax[n1];
    // construct an array with element representing maximum to the right side of that element.
 
    for(i=n1-1;i>=0;i--) Rmax[i]=(i==n1-1||B[i]>=Rmax[i+1]?B[i]:Rmax[i+1]);
    
    for(i=0,j=0;i<n1 && j<n1;)
    {
        //printf("%d %d",B[i], Rmax[j]);
        if(B[i]<=Rmax[j])
        {
            if((j-i)>maxValue)
            {
                maxValue=(j-i);
                //printf("%d ",maxValue);
            }
            j++;
        }
        else
        {
            i++;
        }
    }
    
    return maxValue;
}
