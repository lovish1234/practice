/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns 
 */
 
int k;

int factorial(int n)
{
    int i,ans=1;
    for(i=1;i<=n;i++)
    {
        ans*=i;
    }
    return ans;
}

void init()
{
    k=0;
}

void getSets(int *A, int index, int length, int* temp, int* flag, int** result)
{
    int i,j;
    if(index==(length))
    {
        /*
        for(i=0;i<length;i++)
        {
            printf("%d ",temp[i]);
        }
        printf("\n");
        */
        
        for(i=0;i<length;i++)
        {
            result[k][i]=temp[i];
        }
        k++;

        return;
    }
    
    for(i=0;i<length;i++)
    {
        if(flag[i]==0)
        {
            temp[index]=A[i];
            flag[i]=1;
            /*
            for(j=0;j<length;j++)
            {
                 printf("%d ",flag[j]);
            }
            printf("\n");
            */
            
            getSets(A, index+1, length, temp, flag, result);
            flag[i]=0;
            
        }
    }
    
    
}

int ** permute(int* A, int n1, int *len1, int *len2) {
    *len2=n1;
    int i;
    if(n1==0)
    {
        int** result=(int**)malloc(sizeof(int*)*(0));
        for(i=0;i<(*len1);i++)
        {
            result[i]=(int*)malloc(sizeof(int)*(*len2));
        }
    }
    *len1=factorial(n1);
    
    int* temp=(int*)malloc(sizeof(int)*(*len2));
    int * flag=(int*)malloc(sizeof(int)*(*len2));
    for(i=0;i<n1;i++)
    {
        flag[i]=0;
    }
    int** result=(int**)malloc(sizeof(int*)*(*len1));
    for(i=0;i<(*len1);i++)
    {
        result[i]=(int*)malloc(sizeof(int)*(*len2));
    }
    
    init();
    getSets(A, 0, n1, temp, flag, result);
    return result;
}

