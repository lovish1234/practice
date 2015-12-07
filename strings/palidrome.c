/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
 
 
int strLen( char* A)
{
    char *itr = A;
    int count=0;
    while(*itr!='\0')
    {
        itr++;
        count++;
    }
    return count;
}

int finalstrLen( char* A)
{
    char *itr = A;
    int count=0;
    
    while(*itr!='\0')
    {
        if( (*itr>='A' && *itr<='Z') || (*itr>='a' && *itr<='z') || (*itr>='0' && *itr<='9') )
        {
            count++;
           
        }
        itr++;
    }
    return (count+1);
}


char *removeAlphaNumeric(char *A, int finalstrLength)
 {
     char *itr=A;
   
     char *result = (char*)malloc(sizeof(char)*(finalstrLength));
     char *resultItr = result;
     
     while(*itr!='\0')
     {
      
        if( (*itr>='A' && *itr<='Z') || (*itr>='a' && *itr<='z') || (*itr>='0' && *itr<='9') )
         {
             // if it is uppercase
            if(*itr>='A' && *itr<='Z')
            {
                *resultItr = (*itr)-'A'+'a';
            }
            else
            {
                *resultItr = *itr;
            }
            resultItr++;
         }
         
         itr++;
     }
     *resultItr='\0';
     return result;
 }
 
int isPalindrome(char* A) {
    int i=0,j=0;
    int lenA = strLen(A);
    //if empty or a single character
    if(lenA==0 || lenA==1)return 1;
    
    int finallenA = finalstrLen(A);
    if(finallenA==1 || finallenA==2)return 1;
    
    char *final = removeAlphaNumeric(A, finallenA);
    
    
    for(i=0;i<((finallenA-1)/2)+1;i++)
    {
        if(!(final[i]==final[finallenA-i-2]))
        {
            
            return 0;
        
        }
    }
    
    
    return 1;
    
}

