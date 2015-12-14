/**
 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
 
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

int countNonSpaces(const char* A)
{
    char* itr=A;
    int count=0;
    while(*itr!='\0')
    {
        //printf("%c %d \n",*itr,count);
        if(*itr!=' ')
        {
            
            count++;
        }
        itr++;
    }
    return count;
}

/*

int numDecimalValid(const char *A)
{
    char* itr = A;
    int count=0;
    while(*itr!='\0')
    {
        if(*itr=='.')
        {
            count++;
        }
    }
    if(count==1 || count==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int numExponentValid(const char *A)
{
    char* itr = A;
    int count=0;
    while(*itr!='\0')
    {
        if(*itr=='e')
        {
            count++;
        }
    }
    if(count==1 || count==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int posDecimal(const char *A)
{
    char* itr = A;
    int count=0;
    while(*itr!='\0')
    {
        if(*itr=='.')
        {
           break;
        }
        count++;
    }
    return count;
}

int posExponent(const char *A)
{
    char* itr = A;
    int count=0;
    while(*itr!='\0')
    {
        if(*itr=='e')
        {
           break;
        }
        count++;
    }
    return count;
}

*/


int isNumber(const char* A) {
    
    // cases for numberic number itself are less
    // accepted characters are numbers, decimals, exponential, minus and plus
    // cannot have more than one exponential
    
    
    
    if(countNonSpaces(A)==0)
    {
        return 0;
    }
    
    
    
    char* itr=A+removeSpaces(A);
    int flag=0,noSign=0,noSignExp=0;
    while(*itr!='\0')
    {
        // number before decimal, what if ++
        if((*itr=='+' || *itr=='-' || (*itr>='0' && *itr<='9')) && (flag==0 || flag==1))
        {
            if(*itr=='+' || *itr=='-')
            {
                noSign++;
                if(noSign==2)
                {
                    return 0;
                }
            }
            flag=1;
           
        }
        // decimal
        else if(*itr=='.' && (flag==1 || flag==0))
        {
            flag=2;
        
        }
        // number after decimal necessary if there is decimal
        else if(*itr>='0' && *itr<='9' && (flag==2 || flag==3))
        {
            flag=3;

        }
        // exponential
        else if(*itr=='e' && (flag==3 || flag==1 || flag==0))
        {
            flag=4;
        }
        // what if ++
        else if((*itr=='+' || *itr=='-' || (*itr>='0' && *itr<='9')) && (flag==4 || flag==5))
        {
            if(*itr=='+' || *itr=='-')
            {
                noSignExp++;
                if(noSignExp==2)
                {
                    return 0;
                }
            }
            flag=5;
        }
        // handle spaces
        else if(*itr==' ' && (flag==5 || flag==0 || flag==3))
        {
            itr++;
            continue;
        }
        else
        {
            return 0;
        }
        itr++;
    }
    itr--;
    if(*itr=='+' || *itr=='-' || *itr=='.' || *itr=='e' )
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}
