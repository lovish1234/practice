/**
 * @input A : Integer
 * 
 * @Output 2D int array. You need to malloc memory. Fill in number_of_rows as row, number_of_columns as columns 
 */
int ** generateMatrix(int A, int *number_of_rows, int *number_of_columns) {
	
    int i,j,count=1;    
    *number_of_rows = A;
    *number_of_columns = A;
    int **result = (int **)malloc(A * sizeof(int *));
    for(i=0;i<A;i++)
    {
        result[i] = (int*)malloc(A * sizeof(int));
    }
    
    
    if(A==1)
    {
        result[0][0]=1;
        return result;
    }
    int rmin=0, rmax=A-1;
    int cmin=0, cmax=A-1;
    i=0,j=0;
    
    while(rmin<=rmax && cmin<=cmax)
    {
        for(j=cmin;j<=cmax;j++)
        {
            result[rmin][j]=count;
            count++;
        }
        rmin++;
        
        for(i=rmin;i<=rmax;i++)
        {
            result[i][cmax]=count;
            count++;
        }
        cmax--;
        
        for(j=cmax;j>=cmin;j--)
        {
            result[rmax][j]=count;
            count++;
        }
        rmax--;
        
        for(i=rmax;i>=rmin;i--)
        {
            result[i][cmin]=count;
            count++;
        }
        cmin++;
    }
    
    
    
    return result;
         
         
}

