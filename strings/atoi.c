/**
 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
 
/**
 * Get first symbol index
 * 
**/


int removeSpaces(const char* A)
{
    char* itr=A;
    int count=0;
    while(*itr!='\0')
    {
        //printf("%c %d \n",*itr,count);
        if(*itr==' ')
        {
            
            count++;
        }
        else
        {
            break;
        }
        itr++;
    }
    return count;
}

//change extract word to get correct answer
int extractWord(const char* A, int firstIndex)
{
    char* itr=(A+firstIndex);
    int length=0,flag=0;
    while(*itr!='\0')
    {
        if(*itr!=' ')
        {
            if(*itr >='0' && *itr<='9')
            {
                length++;
            }
            else if((*itr=='-' || *itr=='+' ) && flag==0)
            {
                length++;
                flag=1;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
        itr++;
    }
    return length;
}

int checkValidity(const char *A, int firstIndex, int length)
{
    
    int i,flag=0;
    for(i=0;i<length;i++)
    {
        if(A[i+firstIndex] >= '0' && A[i+firstIndex] <= '9')
        {
            flag=1;
            continue;
        }
        else if(A[i+firstIndex]=='-' && flag==0)
        {
            flag=1;
            continue;
        }
        else if(A[i+firstIndex]=='+' && flag==0)
        {
            flag=1;
            continue;
            
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int getStringValue( const char *A, int firstIndex, int length)
{
    
    int i=0;
    long long int ans=0;
    int sign=1;
    if(A[firstIndex]=='-')
    {
        sign=-1;
        i++;
    }
    
    if(A[firstIndex]=='+')
    {
        sign=1;
        i++;
    }
    
    if(sign==1)
    {
        while(i<length)
        {
           ans+=pow(10,length-i-1)*(A[i+firstIndex]-'0');   
           if(ans > INT_MAX)
           {
               return INT_MAX;
           }
          // printf(" %d %d %d %d \n",i,power,A[i+firstIndex],ans);
           i++;
        
        }
    }
    else
    {
        while(i<length)
        {
           ans-=pow(10,length-i-1)*(A[i+firstIndex]-'0');   
           if(ans < INT_MIN)
           {
               return INT_MIN;
           }
          // printf(" %d %d %d %d \n",i,power,A[i+firstIndex],ans);
           i++;
        
        }
        
    }
    return ans;
}


int matoi(const char* A) {
    int firstI = removeSpaces(A);
    int firstL = extractWord(A,firstI);
    int firstV = checkValidity(A,firstI,firstL);
    
    //printf(" %d %d %d \n",firstI,firstL,firstV);
    
    if(firstV==0)
    {
        return 0;
    }
    else
    {
        return getStringValue(A,firstI,firstL);
        
    }
}
