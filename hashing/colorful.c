/**
 * @input A : Integer
 * 
 * @Output Integer
 */
 
  int comparator(const void* a, const void* b) {
        int value1 = *((int *)a);
        int value2 = *((int *)b);
        if (value1 < value2) {
            // Return -1 if you want ascending. 1 if you want descending. 
            return -1;
        } else if (value1 > value2) {
            // Return 1 if you want ascending. -1 if you want descending. 
            return 1;
        }
        return 0;
    }

int numSize(int A)
{
    int temp=A,ans=0;
    while(temp>0)
    {
        ans++;
        temp=temp/10;
    }
    //printf("%d\n",ans);
    return ans;
}

void numArray(int A, int size, int *number)
{
    int i;
    int temp=A;
    for(i=0;i<size;i++)
    {
        number[size-i-1]=temp%10;
        //printf("%d %d\n",size-i-1,temp%10);
        temp/=10;
    }

}
int colorful(int A) {
    
    int size= numSize(A),i,j;
    int *number=(int*)malloc(sizeof(int)*size);
    numArray(A,size,number);
    
    int array[size][size];
    int fsize=(size)*(size+1)/2;
    int farray[fsize],k=0;
    
    for(i=0;i<size;i++)
    {
        array[i][i]=number[i];
        //printf("%d %d %d\n",i,i,array[i][i]);

    }
    
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            array[i][j]=array[i][j-1]*array[j][j];
            //printf("%d %d %d\n",i,j,array[i][j]);
        }
        
    }
    
    for(i=0;i<size;i++)
    {
        for(j=i;j<size;j++)
        {
            farray[k]=array[i][j];
            //printf("%d %d\n",k,farray[k]);
            k++;
        }
        
    }
    
    //printf("%d\n",fsize);
    
    qsort(farray,fsize,sizeof(int),comparator);
    
    /*
    for(k=0;k<size;k++)
    {
        printf("%d %d\n",k,farray[k]);
    }
    */
    
    for(k=0;k<fsize-1;k++)
    {
        if(farray[k]==farray[k+1])
        {
            return 0;
        }
    }
    
    return 1;
}

