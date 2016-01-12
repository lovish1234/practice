/**
 * @input A : Integer
 * 
 * @Output string array. You need to malloc memory. 
 *   Fill in len1 as number of strings. Make sure every string ends with null character
 */
//int count=0;
int k=0;

void init()
{
    k=0;
    //count=0;
}

void getSets(int A, int value, int count, char* temp, char** result)
{
    // prune the sequences where ')' occurs without a prior '('
    if(count<=-1 || (count>=0 && value>2*A))
    {
        return;
    }
    
    int i;
    if(count==0 && value==2*A)
    {
        for(i=0;i<2*A;i++)
        {
            result[k][i]=temp[i];
        }
        result[k][2*A]='\0';
        k++;
        return;
    }
    
    temp[value]='(';
    getSets(A, value+1, count+1, temp, result);
    temp[value]=')';
    getSets(A, value+1, count-1, temp, result);
    
}

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

char** generateParenthesis(int A, int *len1) {
    *len1=20000;
    //printf("%d\n",*len1);
    // need extra space for \0 at end of every parathesis sequence
    char **result= (char**)malloc(sizeof(char*)*(*len1));
    int i;
    for(i=0;i<(*len1);i++)
    {
        result[i]=(char*)malloc(sizeof(char)*(2*A+1));
    }
    char *temp= (char*)malloc(sizeof(char)*(2*A));

    init();
    getSets(A, 0, 0, temp, result);
    *len1=k;
    return result;
}
