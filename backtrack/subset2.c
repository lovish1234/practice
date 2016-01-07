/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row
 * For each row i, A[i][0] should indicate the number of columns in row i.
 * Then A[i][1] to A[i][col] should have the values in those columns.
 */
int k;
int count;


void init()
{
    k=1;
    count=0;
}

int checkDup(int **result, int end)
{
    int i,j,size1, size2, flag;
    for(i=1;i<k;i++)
    {
        flag=0;
        size1=result[i][0];
        size2=result[k][0];
        if(size1==size2)
        {
            for(j=1;j<=size1;j++)
            {
                
                if(result[i][j]==result[k][j])
                {
                    flag++;

                }
            }
            if(flag==size1)
            {
                return 1;
            }
        }
    }
    return 0;
}

void getSets(int *A, int start, int end, int count, int* temp, int** result) 
{
    int i;
    if(start>end)
    {
        return;
    }
    
    
    temp[count]=A[start];
    result[k][0]=count+1;
    for(i=1;i<=(count+1);i++)
    {
        result[k][i]=temp[i-1];
    }
    if(checkDup(result,end)!=1)
    {
        k++;
    }
    getSets(A, start+1, end, count+1, temp, result);
    getSets(A, start+1, end, count, temp, result);
   
}

int comparator(const void *A, const void *B)
{
    int val1= *((int*)A);
    int val2= *((int*)B);
    
    if(val2 > val1)
    {
        return -1;
    }
    else if(val2 < val1)
    {
        return 1;
    }
    return 0;
}

int ** subsetsWithDup(int* A, int n1, int *len1) {
    *len1=pow(2,n1);
    int *temp=(int*)malloc(sizeof(int)*n1);
    int **result=(int**)malloc(sizeof(int*)*(*len1));
    int i;
    for(i=0;i<(*len1);i++)
    {
        result[i]=(int*)malloc(sizeof(int)*(n1+1));
    }
    
    qsort(A,n1,sizeof(int),comparator);
        
    init();    
    result[0][0]=0;
    getSets(A, 0, n1-1, 0, temp, result);
    *len1=k;
    return result;
}
