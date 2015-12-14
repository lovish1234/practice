/**
 * @input A : String termination by '\0'
 * @input B : Integer
 * 
 * @Output string. Make sure the string ends with null character
 */
 
int strLength(char*A)
{
    char *itr=A;
    int count=0;
    while(*itr!='\0')
    {
        count++;
        itr++;
    
    }
    return count;
}

char* convert(char* A, int B) {
    
    char *itr=A;
    int length = strLength(A);
    int i,j,n=0,row,column;
    
    /*
    int* row =(int*)malloc(sizeof(int)*B);
    int* column=(int*)malloc(sizeof(int)*length);
    */
    
    if(B==1)
    {
        return A;
    }
    
    char** S=(char**)malloc(sizeof(char *)*B);
    for(i=0;i<B;i++)
    {
        S[i]=(char*)malloc(sizeof(char)*length);
    }
    
    for(i=0;i<B;i++)
    {
       for(j=0;j<length;j++)
       {
           S[i][j]='\0';
       }
       
    }
    
    for(i=0;i<length;i++)
    {
        //printf("%d\n",i);
        j=i;
        while(j>=2*(B-1))
        {
            j-=2*(B-1);
        }
        //printf("%d\n",i);

        if(j>=0 && j <=(B-1))
        {
            row=j;
        }
        else
        {
            row=2*(B-1)-j;
            
        }
        column=i;
        S[row][column]=A[i];
        //printf(" %d %d %d %d\n",i,j,row,column);
    }

    char* result =(char*)malloc(sizeof(char)*(length+1));
    
    for(i=0;i<B;i++)
    {
        for(j=0;j<length;j++)
        {
            if(S[i][j]!='\0')
            {
                result[n]=S[i][j];
                n++;
            }
        }
    }
    result[n]='\0';
    return result;
}
