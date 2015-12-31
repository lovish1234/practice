/**
 * @input A : String termination by ' * 
 * @Output string array. You need to malloc memory. 
 *   Fill in len1 as number of strings. Make sure every string ends with null character
 */

// a hashtable  
const char hashTable[10][5]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int strLength(char *A)
{
    int count=0;
    char *itrA=A;
    while(*itrA!='\0')
    {
        count++;
        itrA++;
    }
    return count;
}

int numOfStrings(char *A)
{
    int ans=1;
    char *itrA=A;
    
    while(*itrA!='\0')
    {
        if(*itrA=='0' || *itrA=='1')
        {
            ans*=1;
        }
        else if(*itrA=='2' || *itrA=='3' || *itrA=='4' || *itrA=='5' || *itrA=='6' || *itrA=='8')
        {
            ans*=3;
        }
        else if(*itrA=='7' || *itrA=='9')
        {
            ans*=4;
        }
        else
        {
            ans=0;
            return ans;
        }
        itrA++;
    }
    return ans;
}


void fillResult(char *A, int length, int index, char **result, int lengthOfOutput, int ratio)
{
    int i,j=0,k;
    if(length==index)
    {
        return;
    }
    
    for(i=0;i<strLength(hashTable[(A[index]-'0')]);i++)
    {
        int temp=strLength(hashTable[(A[index]-'0')]);
        while(j<(lengthOfOutput/temp)*(i+1))
        {
            for(k=0;k<ratio;k++)
            {
                result[j+k*ratio][index] = hashTable[(A[index]-'0')][i];
                
            }
            j++;
        }
        
        
        fillResult(A, length, index+1, result, (lengthOfOutput/temp), temp);
        
    }
}



// assuming - length of string not 0, does not contain * or #, terminating at \0, not *
char** letterCombinations(char* A, int *len1) {
    char* itrA=A;
    int i,j;
    int length=strLength(A);
    int lengthOfOutput= numOfStrings(A);
    
    *len1=lengthOfOutput;
    char **result=(char **)malloc(sizeof(char*)*(*len1));
    for(i=0;i<(*len1);i++)
    {
        result[i]=(char*)malloc(sizeof(char)*(length+1));
    }
    
    // end all the strings with dilimiter
    for(i=0;i<(*len1);i++)
    {
        result[i][length]='\0';
    }
    
    // recursive function to fill in all the length
    fillResult(A,length,0,result,lengthOfOutput,1);
    
    return result;
}
