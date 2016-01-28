
int comparator(void *A, void *B)
{
    int value1=*((int*)A);
    int value2=*((int*)B);
    
    if(value2>value1)
    {
        return -1;
    }
    else if(value1>value2)
    {
        return 1;
    }
    return 0;
}

int checkDup(int **A, int numsol)
{
    int i;
    for(i=0;i<numsol;i++)
    {
        if(A[i][0]==A[numsol][0] && A[i][1]==A[numsol][1] && A[i][2]==A[numsol][2] && A[i][3]==A[numsol][3])
        {
            return 1;
        }
    }
    return 0;
}


int ** fourSum(int* A, int n1, int B, int *len1, int *len2) 

{

    int i=0,j=1,k=j+1,l=n1-1,numsol=0;
    *len1=100000,*len2=4;
    qsort(A,n1,sizeof(int),comparator);
    int** result=(int**)malloc(sizeof(int*)*(*len1));
    for(i=0;i<n1-2;i++)
    {
        for(j=i+1;j<n1-1;j++)
        {
            k=j+1;
            l=n1-1;
            while(k<l)
            {
                if((B-A[i]-A[j])==(A[k]+A[l]))
                {
                    result[numsol]=(int*)malloc(sizeof(int)*(4));
                    result[numsol][0]=A[i];
                    result[numsol][1]=A[j];
                    result[numsol][2]=A[k];
                    result[numsol][3]=A[l];
                    l--;
                    if(!checkDup(result,numsol))
                    {
                        numsol++;
                    }
                }
                else if((B-A[i]-A[j])>(A[k]+A[l]))
                {
                    k++;   
                }
                else
                {
                    l--;
                }
            }
        }
    }
    
    *len1=numsol;

    return result;

}
