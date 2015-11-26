/**
 * @input A : 2D integer array ' * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * @input B : Integer
 * 
 * @Output Integer
 */
int searchMatrix(int** A, int n11, int n12, int B) {
    
    int low=0, high=(n11*n12-1),mid,midR,midC;
    

    while(low<=high)
    {
        
        mid = low + ((high-low)/2);
        midR = mid/n12;
        midC = mid%n12;
        
        if(A[midR][midC]==B)
        {
            
            return 1;
        }
        else if (A[midR][midC]>B)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        
    }
    return 0;
}
