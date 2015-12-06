/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
 
int pivot( const int* A, int n1)
{
    int low=0, high=n1-1, mid;
    int next,prev;
    
    while(low<=high)
    {
        
    // the array has not been rotated
    if(A[low]<=A[high])
    {
        //binary search 
        return low;
    }
    
    // the array has been rotated
    
    mid = low + (high-low)/2;
    next = (mid+1)%n1;
    prev = (mid+n1-1)%n1;
    
    if(A[mid] <= A[next] && A[mid] <= A[prev])
    {
        // found the pivot
        return mid;
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

int binarySearch(int *array, int n1, int B, int p)
{
    int low=0, high=low+n1-1,mid;
    int lowR=low+p, highR=(p+high)%n1,midR;
    while(low<=high)
    {
        mid = low + (high-low)/2;
       // printf("%d %d %d\n",low,high,mid);
        midR = (mid+p)%n1;
       // printf("%d %d %d\n",lowR,highR,midR);
        if(array[midR]==B)
        {
            return midR;
        }
        else if (array[midR]>B)
        {
            highR = (midR-1+n1)%n1;
            high = (highR-p+n1)%n1;
        }
        else
        {
            lowR = (midR+1)%n1;
            low = (lowR-p+n1)%n1;
        }
       // printf("%d %d %d\n",low,high,highR);

    }
    return -1;
    
}

int search(const int* A, int n1, int B) {
    
   // int *array = (int*)malloc(sizeof(int)*n1);
    int i, p = pivot(A,n1);
   
    
    int position = binarySearch(A, n1, B, p);
    if (position==-1) return -1;
    
    return position;
    
    
}

