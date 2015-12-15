/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 */

int strLength(char *A)
{
    int count=0;
    char* itr=A;
    
    while(*itr!='\0')
    {
        count++;
        itr++;
    }
    return count;
}

int checkPalindrome(char *A, int start, int end)
{
    int i;
    int length=(end-start+1);
    for(i=0;i<((length/2)+1);i++)
    {
        if(A[start+i]!=A[end-i])
        {
            return 0;
        }
    }
    return 1;
}

char* longestPalindrome(char* A) 
{
    int start,end;
    int length=strLength(A);
    if(length==0 || length==1)
    {
        return A; 
    }
    int maxLength=INT_MIN,imax=-1,jmax=-1,i,j,diff;
    
    int palinMatrix[length][length];
    
    
    
    for(i=0;i<length;i++)
    {
        for(j=i;j<length;j++)
        {
            if(i==j)
            {
                palinMatrix[i][j]=1;
                if((j-i+1)>maxLength)
                {
                    imax=i;
                    jmax=j;
                    maxLength=(j-i+1);
                }
            }
            else if(j==i+1)
            {
                palinMatrix[i][j]=(A[i]==A[j]);
                if(A[i]==A[j])
                {
                    if((j-i+1)>maxLength)
                    {
                        imax=i;
                        jmax=j;
                        maxLength=(j-i+1);
                    }
                }
            }
            else
            {
                palinMatrix[i][j]=0;
            }
            
        }
    }
    
    //printf("%d\n",length); 
    for(diff=2;diff<length;diff++)
    {
        //printf("%d\n",length-diff);
        for(i=0;i<length-diff;i++)
        {
                
                j=i+diff;
                if(palinMatrix[i+1][j-1]==1 && A[i]==A[j])
                {
                    palinMatrix[i][j]=1;
                    if((j-i+1)>maxLength)
                    {
                        imax=i;
                        jmax=j;
                        maxLength=(j-i+1);
                    }
                }
                else
                {
                    palinMatrix[i][j]=0;
                }
            
            
        }
    }
    
    

    //printf("%d %d %d\n",imax,jmax,maxLength);
    char* result= (char*)malloc(sizeof(char)*(maxLength+1));
    
    for(i=0;i<maxLength;i++)
    {
        result[i]=A[imax+i];
    }
    result[i]='\0';
    
    return result;
}
