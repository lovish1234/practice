/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int diffPossible(int* A, int n1, int B) {
    
    int i,j,minDiff=INT_MAX,minIndex;
    
    // trivial condition
    if(A[n1-1]-A[0] < B)
    {
        return 0;
    }
    
    //a linear scan to find out pair of concecutive elements with minimum difference
    
    /*
    for(i=0;i<(n1-1);i++)
    {
        j=i+1;
        if(A[j]-A[i] < minDiff)
        {
            minIndex=i;
            minDiff=(A[j]-A[i]);
        }
    }
    */
    
    /*
    if(A[minIndex+1]-A[minIndex]>B)
    {
        return 0;
    }
    
    i=minIndex;
    j=minIndex+1;
    
    while(j>i)
    {
        if((A[j]-A[i])==B)
        {
            return 1;
        }
        if((A[j]-A[i])>B)
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    */
    
    // a new array with 
   i=0;
   j=1;
   while((i<n1) && (j<n1))
   {
       if(i!=j && A[j]-A[i]==B)
       {
           return 1;
       }
       if(A[j]-A[i]<B)
       {
           j++;
           
       }
       else
       {
           i++;
       }
   }
   return 0;
}
