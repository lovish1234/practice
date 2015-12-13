/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns 
 * len2 will be 3 here as you have to report triplets.
 */
 
int comparator(const void *A, const void *B)
{
    int value1 = *(int*)A;
    int value2 = *(int*)B;
    
    if(value1 > value2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    
}
int ** threeSum(int* A, int n1, int *len1, int *len2) {
    
    *len2 = 3;
    qsort(A,n1,sizeof(int),comparator);
    
    
    
    int i=0,j,k,sum,count=0,dup=0;
    
    // removing duplicate elements
    int prev = A[0];
    for(i=1;i<n1;i++)
    {
        if(A[i]==prev)
        {
            dup++;
        }
        prev=A[i];
    }
    
    int finalLength=n1-dup;
    int *B = (int*)malloc(sizeof(int)*(finalLength));
    
    prev=A[0];
    B[0]=A[0];
    int s=1;
    for(i=1;i<(n1);i++)
    {
        if(A[i]==prev)
        {
            continue;
        }
        else
        {
            B[s]=A[i];
            s++;
        }
        prev=A[i];
    }
    
    
    /*
    for(s=0;s<finalLength;s++)
    {
        printf("%d ",B[s]);
    }
    printf("\n");
    */
    
    for(i=0;i<finalLength;i++)
    {
        j=i+1;
        k=finalLength-1;
        while(j<k)
        {
            sum= B[i]+B[j]+B[k];
            if(sum==0)
            {
                count++;
            }
            if(sum>0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
        
    }
    
    //printf("%d\n",count);
    
    int l=0;
    *len1 = count;
    int** result = (int**)malloc(sizeof(int*)*(*len1));
    for(l=0;l<count;l++)
    {
        result[l] = (int*)malloc(sizeof(int)*(*len2));
    }
    
    l=0;
    for(i=0;i<finalLength;i++)
    {
        j=i+1;
        k=finalLength-1;
        while(j<k)
        {
            sum= B[i]+B[j]+B[k];
            if(sum==0)
            {
                result[l][0]=B[i];
                result[l][1]=B[j];
                result[l][2]=B[k];
                l++;
            }
            if(sum>0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
        
    }
    
    return result;
}
