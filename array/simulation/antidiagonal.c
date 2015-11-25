/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, and first entry in result array must be size of that row.  
 */
int ** diagonal(int** A, int n11, int n12, int *len1) {
    
    *len1 = 2*n11-1;
    int i,j,sum,count,size=1;

    
    int** result = (int**)malloc(sizeof(int*)*(2*(*len1)-1));
    for(i=0;i<(2*(*len1)-1);i++)
    {
        result[i] = (int*)malloc(sizeof(int)*(size+1));
        i<((n11+n12-1)/2)?size++:size--;
    }
    
    
    size=1;
    for(sum=0;sum<(n11+n12-1);sum++)
    {
        count=1;
        result[sum][0]= size;
        //printf("%d %d %d\n",sum,0,size);
        sum<((n11+n12-1)/2)?size++:size--;
        
        for(i=0;i<n11;i++)
        {
            j=sum-i;
            if(i <0 || j<0 || j>= n11)
            {
                continue;
            }
            else
            {
                result[sum][count] = A[i][j];
                //printf(" %d %d %d %d %d %d\n" ,sum,count,i,j,result[sum][count],A[i][j]);
                count++;
                j--;
            }
        }
    }
    
    return result;
}



