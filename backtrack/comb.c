/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row
 * For each row i, A[i][0] should indicate the number of columns in row i.
 * Then A[i][1] to A[i][col] should have the values in those columns.
 */

int count;
int k;

void init()
{
    count=0;
    k=0;
}
/**
 * Remove the duplicate elements from initial array
 */
int dupSet(int * A, int n1)
{
    int i,j,k;
    for(i=0;i<n1;i++) 
    {
      for(j=i+1;j<n1; )
        {
         if(A[j]==A[i])
         {
            for(k=j;k<n1;k++) 
            {
               A[k]=A[k+1];
            }
            n1--;
         }
         else 
         {
            j++;
         }
        }
    }
    
    return n1;
}

/**
 * Remove the duplicates in final result
 * Not required here but required in comb2.c
 */
int checkDup(int ** result)
{
    int size1= result[k-1][0];
    int size2= result[k][0];
    int i;
    if(size1==size2)
    {
        for(i=1;i<size1;i++)
        {
            if(result[k][i]!=result[k-1][i])
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }
    return 1;
}


void getSets(int *A, int start, int end, int count, int sum, int **result, int *temp)
{
    int i;
    // if the remaining sum is greater than present element, we have to prune than branch
    // or if we have exceeded the length of set, we have to stop
 
    temp[count]=A[start];
    //  take the present element in sum
    
    
    if(sum==0 )
    {

        // store the size in first coulumn of every row

        result[k][0]=count;
        for(i=0;i<=count;i++)
        {
            result[k][i+1]=temp[i];
        }
        if(k!=0 && checkDup(result)!=1)
        {
            k++;
        }
        if(k==0)
        {
            k++;
        }
        
        return;
    }
    if(start>end)
    {
        return;
    }
    
    if(sum>0 && (sum-temp[count]>=0))
    {
        // we want to take present element one time and give it another chance
        getSets(A,start,end, count+1, (sum-temp[count]), result, temp);
    
        // do not take the present element in sum
        getSets(A, start+1, end, count, sum, result, temp);
    }
    else
    {
        return;
    }


}

int comparator(const void *A, const void* B)
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

int ** combinationSum(int* A, int n1, int B, int *len1) {
    
    qsort(A,n1,sizeof(int),comparator);
    n1=dupSet(A,n1);
    int i;
    

    *len1= pow(2,n1);
    int *temp=(int*)malloc(sizeof(int)*B);
    int **result=(int**)malloc(sizeof(int*)*(*len1));
    for(i=0;i<(*len1);i++)
    {
        result[i]=(int*)malloc(sizeof(int)*(B+1));
    }
    int prev=0;
    init();
    getSets(A,0,n1-1,0,B,result,temp);
    *len1=k;
    return result;
}
