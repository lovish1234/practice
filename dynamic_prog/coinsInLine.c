/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
 
int min(int a, int b)
{
    return a>b?b:a;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int maxcoin(int* A, int n1) 
{
    int** array = (int**)malloc(sizeof(int*)*n1);
    int i,j;
    for(i=0;i<n1;i++)
    {
        array[i]=(int*)malloc(sizeof(int)*n1);
    }
    
    for ( i = n1 - 1; i >= 0; i--) 
    {
        for ( j = i; j < n1; j++) 
        {
            if (i == j) 
            {
                array[i][j] = A[i];
            }
            else if (i + 1 == j) 
            {
                array[i][j] = max(A[i], A[j]);
            }
            else 
            {
                int case1 = A[i] + min(array[i + 2][j], array[i + 1][j - 1]);
                int case2 = A[j] + min(array[i][j - 2], array[i + 1][j - 1]);
                array[i][j] = max(case1, case2);
            }
        }
    }
    return array[0][n1 - 1];
}
