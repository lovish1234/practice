/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int findCount(const int* A, int n1, int B) {
    int low=0, high=n1-1,mid,index=-1,i,count=0;
    
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if (A[mid]==B)
        {
            index=mid;
            for(i=mid-1;i>=0;i--)
            {
                if(A[i]==B)
                {
                    count++;
                }
            }
            
            for(i=mid+1;i<n1;i++)
            {
                if(A[i]==B)
                {
                    count++;
                }
            }
            return (count+1);
        }
        else if(A[mid] < B)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    
    return 0;
}
