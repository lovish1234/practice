/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int majorityElement(const int* A, int n1) {
    int i, element=0, count=1;
    
    for(i=1;i<n1;i++)
    {
        if(A[i]==A[element])
        {
            count++;
        }
        else 
        {
            count--;
        }
        
        if(count==0)
        {
            element=i;
            count=1;
        }
    }
    return A[element];
}

