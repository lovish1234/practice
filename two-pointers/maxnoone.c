/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* maxone(int* A, int n1, int B, int *len1) {
    
    // two index denoting start and end of the series of 1's
    int i=0,j=0,zeros=0;
    int length=INT_MIN,max_length=0,i_max,j_max;
    while(j<n1)
    {
        if(A[j]==1)
        {
            
            length=j-i+1;
            if(length > max_length)
            {
                max_length=length;
                i_max=i;
                j_max=j;
            }
            j++;
        }
        else
        {
            if(zeros<B)
            {
                
                length=j-i+1;
                if(length > max_length)
                {
                    max_length=length;
                    i_max=i;
                    j_max=j;
                }
                zeros++;
                j++;
            }
            else
            {
                // eliminate one zero from initial part
                
                while(A[i]==1)
                {
                    i++;
                }
                i++;
                zeros--;
            }
        }
    }
   // printf(" %d %d %d \n",max_length,i_max,j_max);
    
    *len1=max_length;
    int*result =(int*)malloc(sizeof(int)*max_length);
    for(i=0;i<max_length;i++)
    {
        result[i]=i_max+i;
    }
    
  
    return result;
}
