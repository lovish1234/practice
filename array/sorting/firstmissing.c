/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int firstMissingPositive(int* A, int n1) {
    
    // using hash entries corresponding to each integer, we can check
    // if an integer is present in the array or not. 
    
    int i, quotient, remainde;
    
  
    for(i=0;i<n1;i++)
    {
        if(A[i]>n1 || A[i] <0)
        {
            A[i]=0;
        }
    }
    
    for(i=0;i<n1;i++)
    {
        remainde = A[i]%(n1+1);
        if(remainde!=0)
        {
            A[remainde-1] = A[remainde-1] + (n1+1);
        }
    }
    
    for(i=0;i<n1;i++)
    {
        quotient = A[i]/(n1+1);
        if(quotient==0)
        {
            return (i+1);
        }
    }
    
    return (n1+1);
}
