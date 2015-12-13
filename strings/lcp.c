/**
 * @input A : array of strings termination by '\0'
 * @input n1 : number of strings in array A
 * 
 * @Output string. Make sure the string is '\0' terminated.
 */
 
int strLength(char *B)
{
    char *itr=B;
    int count=0;
    while(*itr!='\0')
    {
        itr++;
        count++;
        //printf("%d\n",count);
    }
    return count;
}

 
char* longestCommonPrefix(char** A, int n1) {
    
    int i,j,minLength=INT_MAX,minLengthIndex=0,count,finalCount=0;
    char *itr;
    
    // check length of every string to choose minimum length
    for(i=0;i<n1;i++)
    {
        itr=A[i];
        minLengthIndex=(strLength(itr)<minLength)?i:minLengthIndex;
        minLength=(strLength(itr)<minLength)?strLength(itr):minLength;
        
    }
    //printf("%d %d\n",minLength,minLengthIndex);
    
    
    for(j=0;j<minLength;j++)
    {
        count=0;
        for(i=0;i<n1;i++)
        {
            if(A[i][j]==A[minLengthIndex][j])
            {
                count++;
            }
        }
        if(count==n1)
        {
            finalCount++;
        }
        //printf("%d\n",count);
        
    }
    
    char* result = (char*)malloc(sizeof(char)*(finalCount+1));
    for(j=0;j<(finalCount);j++)
    {
        result[j]=A[minLengthIndex][j];
    }
    result[j]='\0';
    //printf("%d\n",finalCount);
    
    return result;
    
 
}
