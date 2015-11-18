/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Void. Just modifies the args passed by reference 
 */
void arrange(int* A, int n1) 
{
    // combining two numbers in one index. 
    int i;
    for(i=0;i<n1;i++)
    {
        A[i] = A[i] + (A[A[i]]%n1) * n1;
    }
    
    for(i=0;i<n1;i++)
    {
        A[i] = A[i]/n1;
    }
    
}
