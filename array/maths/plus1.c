/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */

int* truncateZeros(int *A, int n1 )
{
    int i,count=0;
    for(i=0;i<n1;i++)
    {
        if(A[i]==0)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    
    int finalLength = n1-count;
    printf("%d\n",finalLength);
    
    int B[finalLength];
    
    for(i=0;i<finalLength;i++)
    {
        B[i]=A[i+count];
        printf("%d ",B[i]);
    }
    free(A);
    return B;
}
 
int* plusOne(int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
        
         *length_of_array = n1 + 1; // length of result array
         int *result = (int *) malloc(*length_of_array * sizeof(int));
         
         // DO STUFF HERE. NOTE : length_of_array can be n1 OR n1 + 1.
         int i, newValue, carryOver=1;
         
         for(i=0;i<=n1;i++)
         {
             result[i]=0;
         }
         
         for(i=n1-1;i>=0;i--)
         {
             
             newValue = A[i] + carryOver;
             if (newValue >=10)
             {
                 result[i+1]=newValue%10;
                 carryOver=newValue/10;
             }
             else
             {
                 result[i+1]=newValue;
                 carryOver=0;
             }
             
         }
         result[0]=carryOver;
         
    int count=0;
    for(i=0;i<n1;i++)
    {
        if(result[i]==0)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    
    int finalLength = *length_of_array - count;
   
    
    int *B = (int*)malloc(sizeof(int)*(finalLength));
    
    for(i=0;i<finalLength;i++)
    {
        B[i]=result[i+count];
        //printf("%d ",B[i]);
    }
    
    // Malloc allocates more memory than required. Hence, need to reset the length of array 
    // Hence fill the result in *length_of_array space. 
    *length_of_array = finalLength;
    
    
    return B;
         
         
         
}
