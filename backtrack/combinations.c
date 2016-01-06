/**
 * @input n : Integer
 * @input k : Integer
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns 
 */
 
int count;
int x;

int sizeOfResult(int n, int k)
{
    int i,num=1,den=1,ans;
    for(i=(k+1);i<=n;i++)
    {
        num*=i;
    }
    
    for(i=1;i<=(n-k);i++)
    {
        den*=i;
    }
    
    ans=(num/den);
    return ans;
}

void init()
{
    count=0;
    x=0;
}

void getSets(int start, int end, int count, int k, int *temp, int** result)
{
    int i;
    //printf("%d %d %d %d\n", start, end, count,k);
    if(count==k)
    {
        //printf("Reached\n");
        for(i=0;i<count;i++)
        {
            result[x][i]=temp[i];
            //printf("%d %d %d %d ",x, i, temp[i], result[x][i]);
        }
        //printf("\n");
        x++;
        return;
    }
    
    if(start>end)
    {
        return;
    }
    temp[count]=start;
    //printf("%d\n",temp[count]);
    getSets(start+1,end,count+1,k,temp,result);
    getSets(start+1,end,count,k,temp,result);
    
    
}

int ** combine(int n, int k, int *len1, int *len2) {
    
    //int* array=(int*)malloc(sizeof(int)*n);
    int i;
    if(n==0 || k>n)
    {
        *len1=0;
        *len2=0;
        int **result=(int**)malloc(sizeof(int*)*(*len1));
        for(i=0;i<(*len1);i++)
        {
            result[i]=(int*)malloc(sizeof(int)*(*len2));
        }
        return result;
    }
    
    if(k==0)
    {
        *len1=1;
        *len2=0;
        int **result=(int**)malloc(sizeof(int*)*(*len1));
        for(i=0;i<(*len1);i++)
        {
            result[i]=(int*)malloc(sizeof(int)*(*len2));
        }
        return result;
    }
    if(n==k)
    {
        *len1=1;
        *len2=n;
        int **result=(int**)malloc(sizeof(int*)*(*len1));
        for(i=0;i<(*len1);i++)
        {
            result[i]=(int*)malloc(sizeof(int)*(*len2));
        }
        for(i=0;i<n;i++)
        {
            result[0][i]=i+1;
        }
        return result;
    }
    
    
    *len1=sizeOfResult(n,k);
    *len2=k;
    int *temp=(int*)malloc(sizeof(int)*(*len1));
    int **result=(int**)malloc(sizeof(int*)*(*len1));
    for(i=0;i<(*len1);i++)
    {
        result[i]=(int*)malloc(sizeof(int)*(*len2));
    }
    
    init();
    getSets(1,n,count,k,temp,result);
    return result;
}
