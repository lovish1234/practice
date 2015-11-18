/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Void. Just modifies the args passed by reference 
 */
 
int maximum( int i1, int i2)
{
    if(i1 > i2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void markRowTwo( int **A,  int row, int n12)
{
    int i;
    for(i=0;i<n12;i++)
    {
        if(A[row][i]!=0)
        {
            A[row][i]=2;
        }
    }
}

void markColumnTwo( int **A, int column, int n11)
{
    int i;
    for(i=0;i<n11;i++)
    {
        if(A[i][column]!=0)
        {
            A[i][column]=2;
        }
    }
}




void setZeroes(int** A, int n11, int n12) 
{
    int i,j;
    
    for(i=0;i<n11;i++)
    {
        for(j=0;j<n12;j++)
        {
            if(A[i][j]==0)
            {
                markRowTwo(A,i,n12);
                markColumnTwo(A,j,n11);
            }
        }
    }
    
    for(i=0;i<n11;i++)
    {
        for(j=0;j<n12;j++)
        {
            if(A[i][j]==2)
            {
                A[i][j]=0;
            }
        }
    }
}
