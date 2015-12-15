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
    if(length==0 )
    {
        return A; 
    }
    int maxLength=1,imax=0,jmax=0,i,j,diff;
    
    int palinMatrix[length];
    int baseMatrix[length];
    
    for(i=0;i<length;i++)
    {
        baseMatrix[i]=1;
        palinMatrix[i]=0;
    }
    
    /*
    for(i=0;i<length;i++)
    {
        printf("%d ",baseMatrix[i]);
    }
    printf("\n");
    */
    
    
    
    // difference 1
    for(diff=1;diff<2;diff++)
    {
        for(i=0;j<length-diff;i++)
        {
            j=i+diff;
            palinMatrix[i]=(A[i]==A[j]);
            
            if( palinMatrix[i] && (j-i+1)>maxLength)
            {
                imax=i;
                jmax=j;
                maxLength=(j-i+1);
            }
            
        }
    }
    
    /*
    for(i=0;i<length;i++)
    {
        printf("%d ",palinMatrix[i]);
    }
    printf("\n");
    */
    
    //printf("%d\n",length); 
    for(diff=2;diff<length;diff++)
    {
        //printf("%d\n",length-diff);
        for(i=0;i<length-diff;i++)
        {
                
            j=i+diff;
            if(diff%2==0)
            {
                baseMatrix[i]=(baseMatrix[i+1] && (A[i]==A[j]));
                if(baseMatrix[i] && (j-i+1)>maxLength)
                {
                    imax=i;
                    jmax=j;
                    maxLength=(j-i+1);
                    
                }
            }
            else
            {
                palinMatrix[i]=(palinMatrix[i+1] && (A[i]==A[j]));
                if(palinMatrix[i] && (j-i+1)>maxLength)
                {
                    imax=i;
                    jmax=j;
                    maxLength=(j-i+1);
                    
                }
            }
            
            
        }
        
        
        /*
        if(diff%2==0)
        {
        for(i=0;i<length;i++)
        {
            printf("%d ",baseMatrix[i]);
        }
        printf("\n");
        }
        else
        {
        for(i=0;i<length;i++)
        {
           printf("%d ",palinMatrix[i]);
        }
        printf("\n");
        }
        */
        
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
