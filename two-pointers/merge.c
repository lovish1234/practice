/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Return Returns a array of size n1 + n2 with A and B merged. 
 */
int* merge(int* A, int n1, int* B, int n2) {
    int i=0,j=0,k=0;
    int* C = (int*)malloc(sizeof(int)*(n1+n2));
    while(i<n1 && j<n2)
    {
        if(A[i]<B[j])
        {
            C[k]=A[i];
            i++;
        }
        else
        {
            C[k]=B[j];
            j++;
        }
        k++;
        
    }
    if(i==n1)
    {
        while(j<n2)
        {
            C[k]=B[j];
            j++;
            k++;
        }
    }
    
    if(j==n2)
    {
        while(i<n1)
        {
            C[k]=A[i];
            i++;
            k++;
        }
    }
    //printf("%d\n",k);
    return C;
    
}
