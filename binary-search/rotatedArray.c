/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int findMin(const int* A, int n1) {
    
    // number of times array is rotated the index of minimum element
    
    int low=0, high=n1-1, mid;
    int next, prev;
    
    while(low <= high)
    {
        
        
        // this means that array has not been rotated 
        if(A[low]<=A[high])
        {
            return A[low];
        }
        
        mid = low + (high-low)/2;
        next = (mid+1)%n1;
        prev = (mid+n1-1)%n1;
        
        if(A[mid] <= A[next] && A[mid] <= A[prev])
        {
            return A[mid];
        }
        
        if(A[mid] <= A[high])
        {
            high = mid-1;
        }
        
        if(A[mid] >= A[low])
        {
            low = mid+1;
        }
    }
}
