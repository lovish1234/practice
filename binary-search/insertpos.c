/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int searchInsert(int* A, int n1, int B) {
    int low=0,high=n1-1,mid;
    if(B<A[0])
    {
        return 0;
    }
    
    if(B>A[n1-1])
    {
        return n1;
    }
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(A[mid]==B)
        {
            return mid;
        }
        else if (A[mid]<B)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return (low);
}
