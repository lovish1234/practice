/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int removeDuplicates(int* A, int n1) {
    int i,j,dup=0,currentDup=0;
    for(i=0;i<(n1-1);i++)
    {
        j=i+1;
        if(A[i]==A[j])
        {
            currentDup++;
            dup++;
        }
        else
        {
            A[j-dup]=A[j];
        }
        
    }
    return (n1-dup);
}
