/**
 * @input A : Read only ( DON'T MODIFY ) 2D integer array ' * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
 
void recursivePrint( const int** A, int n11, int n12, int * result, int resPtr) 
{
    int itrR, itrC, itrRes=0;
    if (n11==1 && n12==1)
    {
         result[0+resPtr]=A[0][0];
    }
    else if (n11==1)
    {
        for(itrC=0; itrC < n12 ; itrC++)
        {
            result[itrC+resPtr]=A[0][itrC];
        }
    }
    else if (n12==1)
    {
        for(itrR=0; itrR < n11; itrR++)
        {
            result[itrR+resPtr]=A[itrR][0];
        }
    }
    else
    {
        
    /* iterate the first row */
    for ( itrC=0; itrC < n12 ; itrC++,itrRes++)
    {
        result[itrRes + resPtr] = A[0][itrC];
    }
    /* iterate last column */
    for ( itrR=1; itrR < n11; itrR++, itrRes++)
    {
        result[itrRes+resPtr] = A[itrR][n12-1];
    }
    
    /* iterate last row */
    for ( itrC=n12-1; itrC >= 0; itrC --, itrRes++)
    {
        result[itrRes+resPtr] = A[n11-1][itrC];
    }
    
    /* iterate first column */
    for ( itrR=n11-1; itrR >=1; itrR--, itrRes++)
    {
        result[itrRes + resPtr] = A[itrR][0];
    }
    
    
    
    int i,j;
    
    for (i=0 ;i < 2*(n11+n12-2); i++)
    {
        printf("%d ", result[i]);
    }
    int **B = (int **)malloc((n11-2) * sizeof(int *));
    for (i = 0; i < (n11-2); i++) 
    {
        B[i] = (int *)malloc((n12-2) * sizeof(int));
    }
    
    for ( i=0; i< (n11-2) ; i++)
    {
        for ( j=0; j< (n12-2) ; j++)
        {
            B[i][j] = A[i+1][j+1];
        }
    }
    
    recursivePrint( B, n11-2, n12-2, result, 2*(n11+n12-2));
    
    }
}
int* spiralOrder(const int** A, int n11, int n12, int *length_of_array) {
	 *length_of_array = n11 * n12; // length of result array
	 int *result = (int *) malloc(*length_of_array * sizeof(int));
	 // DO STUFF HERE
	 //int i;
	 //int **visited = (int **)malloc((n11) * sizeof(int *));
     //for (i = 0; i < n11; i++) {
        //visited[i] = (int *)malloc((n12) * sizeof(int));
     //}
     

     //recursivePrint(A, n11, n12, result, 0);
     
     int t=0,b=n11-1,l=0,r=n12-1,i,count=0,j=0;
	 while ( t<=b && l<=r )
	 {
	     if ( count%4==0 && l<=r)
	     {
	         for (i=l;i<=r;i++)
	         {
	             //printf("%d, ",A[t][i]);
	             result[j]=A[t][i];
	             j++;
	         }
	         // chop off the top row
	         t++;
	     }
	     else if ( count%4==1 && t<=b)
	     {
	         for (i=t;i<=b;i++)
	         {
	             //printf("%d, ",A[i][r]);
	             result[j]=A[i][r];
	             j++;
	         }
	         r--;
	     }
	     else if ( count%4==2 && l<=r )
	     {
	         for ( i=r;i>=l;i--)
	         {
	             
	             result[j]=A[b][i];
	             j++;
	         }
	         b--;
	     }
	     else  
	     //( count%4==3 && t<=b )
	     {
	         for (i=b;i>=t;i--)
	         {
	             //printf("%d, ",A[i][l])
	             result[j]=A[i][l];
	             j++;
	         }
	         l++;
	     }

	     count++;
	 }
	 return result;
}
