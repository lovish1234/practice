/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row
 * For each row i, A[i][0] should indicate the number of columns in row i.
 * Then A[i][1] to A[i][col] should have the values in those columns.
 */
 
// calculate the size of subset.

int count;
int k;

int cFactorial(int n, int r)
{
    int i,num=1,den=1,ans;
    
    if(n!=0)
    {
        for(i=1;i<=n;i++)
        {
            num*=i;
        }
    }
    else
    {
        num*=1;
    }
    
    if(r!=0)
    {
        for(i=1;i<=r;i++)
        {
            den*=i;
        }
    }
    else
    {
        den*=1;
    }
    
    if((n-r)!=0)
    {
        for(i=1;i<=(n-r);i++)
        {
            den*=i;
        }
    }
    else
    {
        den*=1;
    }
    ans=(num/den);
    return ans;
}

int subsetSize(int n1)
{

    return pow(2,n1);
    
}

void init()
{
    count=0;
    k=1;
}

// count stores the number of elements in the subset 
void getSets(int *A, int start, int end, int count, int **result, int *temp, int pflag)
{
    int p;
    if(pflag==1 && (count)!=0)
    {
        result[k][0]=count;
        for(p=1;p<count+1;p++)
        {
            result[k][p]=temp[p-1];
        }
        k++;
        
    }
    
    
    if(start > end)
    {
        return;
    }
    
    temp[count]=A[start];
    //result[k][count]=A[start];
    
    pflag=1;
    getSets(A,start+1, end, count+1, result, temp, pflag);
    
  
    
    pflag=0;
    getSets(A, start+1, end, count, result, temp, pflag);
    
}

int comparator(const void *A, const void *B)
{
    int val1= *((int *)A);
    int val2= *((int *)B);
    
    if(val1 < val2)
    {
        return -1;
    }
    else if(val1 > val2)
    {
        return 1;
    }
    return 0;
}



int ** subsets(int* A, int n1, int *len1) {
    
    qsort(A, n1, sizeof(int), comparator);
    
    int sSize = subsetSize(n1);
    *len1=sSize;

    int i;
    int **result=(int**)malloc(sizeof(int*)*(*len1));
    for(i=0;i<(*len1);i++)
    {
        // extra element to store size of each subset
        result[i]=(int*)malloc(sizeof(int)*(n1+1));
    }
  
    int *temp=(int *)malloc(sizeof(int)*(n1));
    init();
    
    
    result[0][0]=0;
    getSets(A, 0, n1-1, count, result, temp,0);
    //printf("%d\n",k);


    return result;

}

