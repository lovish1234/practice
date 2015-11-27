/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int singleNumber(const int* A, int n1) {
    
    int i,ans=A[0];
    for(i=1;i<n1;i++)
    {
        ans=ans ^ A[i];
    }
    return ans;
}
