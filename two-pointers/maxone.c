/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Void. Just modifies the args passed by reference 
 */
void sortColors(int* A, int n1) {
    // normally it would take 3*n passes to get this done
    int r=0,w=0,b=0,i;
    
    for(i=0;i<n1;i++)
    {
        if(A[i]==0)
        {
            r++;
        }
        else if(A[i]==1)
        {
            w++;
        }
        else
        {
            b++;
        }
    }
    
    for(i=0;i<n1;i++)
    {
        if(r>0)
        {
            A[i]=0;
            r--;
        }
        else
        {
            if(w>0)
            {
                A[i]=1;
                w--;
            }
            else
            {
                A[i]=2;
                b--;
            }
        }
    }
    
}
