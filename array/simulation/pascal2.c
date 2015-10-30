/**
 * @input A : Integer
 * 
 * @Output 2D int array. You need to malloc memory. Fill in number_of_rows as row.
 * For each row i, A[i][0] should indicate the number of columns in row i. 
 * Then A[i][1] to A[i][col] should have the values in those columns.
 */
int ** generate(int A, int *number_of_rows) {
	
	 
     *number_of_rows = A;
	 int **result = (int **)malloc(A * sizeof(int *));
	 // DO STUFF HERE
	 //int *result_temp=(int *)malloc(A * sizeof(int ));
	 int i,j;
	 for ( i = 0; i < A; i++)
	 {
        result[i] = (int*) malloc((A+1)*sizeof(int));
	 }

	 
	 if(A==0)
     {
         return result;
     }
         
     //Initialize the array
     
     for(i=0;i< *number_of_rows; i++)
     {
         for(j=0;j< (*number_of_rows+1); j++)
         {
             if (j==0)
             {
                 result[i][j]= (i+1);
             }
             else
             {
                 result[i][j]=0;
             }
             //printf("%d", *number_of_rows);
         }
        
     }
     
     
     result[0][1]=1;
         
     // if first row of triangle is asked, return the array
     if(A==1)
     {
             
        return result;
     }
     
         
         
    for( i=1; i<A; i++)
    {
        for( j=1; j<=i+1; j++)
        {
            if (j==1)
            {
                
                result[i][j]=result[i-1][j]+0;
                    
            }
            else
             {
                
                result[i][j]= result[i-1][j]+result[i-1][j-1];
                
                     
                     
             }
        }
             
    }
         
    return result;

}
