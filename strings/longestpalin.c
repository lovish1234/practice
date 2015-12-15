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
    int maxLength=INT_MIN,imax=-1,jmax=-1,i,j;
    
    //this does not look like O(n^2)
    for(i=0;i<length;i++)
    {
        for(j=i;j<length;j++)
        {
            if(checkPalindrome(A,i,j)==1 && (j-i+1)>maxLength)
            {
                maxLength = (j-i+1);
                imax=i;
                jmax=j;
            }
        }
    }
    //printf("%d %d %d\n",imax,jmax,maxLength);
    char* result= (char*)malloc(sizeof(char)*maxLength);
    
    for(i=0;i<maxLength;i++)
    {
        result[i]=A[imax+i];
    }
    return result;
}
