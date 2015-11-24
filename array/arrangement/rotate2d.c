/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Void. Just modifies the args passed by reference 
 */

void swap( int **A, int i1, int j1, int i2, int j2, int i3, int j3, int i4, int j4)
{
    
    int temp2 = A[i2][j2];
    int temp3 = A[i3][j3];
    int temp4 = A[i4][j4];
    
    A[i2][j2] = A[i1][j1];
    A[i3][j3] = temp2;
    A[i4][j4] = temp3;
    A[i1][j1] = temp4;
    
}
 
void rotate(int** A, int n11, int n12) {
    
    // A simple solution would involve reading the array from bottom left of the array.
    // But then not O(1) space. Note that essentialy we have to swap four elements of 
    // the array at the same time. These four elements will take each other's place.
    
    // for loop 1 to n-1 then 2 to n-2 until convergence
    // column would swap to row and new column would be ( n - row )
    
    int i,j,i1,j1,i2,j2,i3,j3,i4,j4;
    
    
    for(i=0;i<(n11/2);i++)
    {
    
    
       
    
    for (j=i;j< (n11-1-i); j++ )
    {
        i1=i;
        j1=j;
        i2=j1;
        j2=n11-1-i1;
        i3=j2;
        j3=n11-1-i2;
        i4=j3;
        j4=n11-1-i3;
        swap(A,i1,j1,i2,j2,i3,j3,i4,j4);
        
    }
    
    }
    /*
    for(i=0;i<n11;i++)
    {
        for(j=0;j<n11;j++)
        {
            printf("%d ",A[i][j]);
        }
    }
    */
}
