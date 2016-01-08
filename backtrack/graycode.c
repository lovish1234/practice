/**
 * @input A : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

int k;

void init()
{
    k=0;
    
}
 
int arrayToBinary(int* temp, int A)
{
    int i,ans=0;
    /*
    for(i=0;i<A;i++)
    {
        printf("%d ",temp[i]);
    }
    printf("\n");
    */
    
    for(i=A-1;i>=0;i--)
    {
        ans+=temp[i]*pow(2,A-1-i);
    }
    //printf("%d\n",ans);
    return ans;
}

int checkDup(int *result, int A)
{
    int i,j;
    for(i=0;i<k;i++)
    {
        if(result[i]==result[k])
        {
            return 1;
        }
    }
    return 0;
}
void getSets(int* result,int* temp, int index, int A)
{
    if(index==A+1)
    {

        return;
    }
    result[k]=arrayToBinary(temp,A);
    if(checkDup(result,A)!=1)
    {
        k++;
    }
    //present bit is flipped
    int i;
    for(i=index;i<A;i++)
    {
        temp[index]=1;
        getSets(result, temp, index+1, A);
    }
    
    // present bit not flipped
    /*
    temp[index]=0;
    getSets(result, temp, index+1, A);
    */
    

    
}
int* grayCode(int A, int *len1) {
    *len1=pow(2,A);
    int *result= (int*)malloc(sizeof(int)*(*len1));
    int *temp=(int*)malloc(sizeof(int)*A);
    int i;
    for(i=0;i<A;i++)
    {
        temp[i]=0;
    }
    
    init();
    getSets(result, temp, 0, A);
    for(i=0;i<pow(2,A);i++)
    {
        printf("%d ",result[i]);
    }
    return result;
}
