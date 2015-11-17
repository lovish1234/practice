/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */


 int compareFunction(const void* a, const void* b) 
 {
        int value1 = *((int *)a);
        int value2 = *((int *)b);
        if (value1 < value2) 
        {
            // Return -1 if you want ascending. 1 if you want descending. 
            return -1;
        }
        else if (value1 > value2) 
        {
            // Return 1 if you want ascending. -1 if you want descending. 
            return 1;
        }
        return 0;
     
 }
    
int* wave(int* A, int n1, int *len1) 
{
        *len1 = n1;
        int *result = (int*)malloc(sizeof(int) * (*len1));
        qsort(A, n1, sizeof(int), compareFunction);
        
        // Now swap every two elements 
        int i,temp;
        if (n1%2==0)
        {
        for(i=0;i<n1;i=i+2)
        {
            temp = A[i];
            A[i]=A[i+1];
            A[i+1]=temp;
        }
        }
        else
        {
        for(i=0;i<n1-2;i=i+2)
        {
            temp = A[i];
            A[i]=A[i+1];
            A[i+1]=temp;
        }
            
        }
        for(i=0;i<n1;i++)
        {
            result[i]=A[i];
        }
        return result;
}

