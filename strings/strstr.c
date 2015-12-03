/**
 * @input haystack : Read only ( DON'T MODIFY ) String termination by '\0'
 * @input needle : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
 
int strLen( const char* A)
{
    char *itr = A,count=0;
    while(*itr!='\0')
    {
        itr++;
        count++;
    }
    return count;
}
 
int strStr(const char* haystack, const char* needle) {
    
    int needleLength = strLen(needle);
    int haystackLength = strLen(haystack);
    int firstIndex,i=0,j=0,subStrLen=0;
    // if needle is empty return -1;
    if(needleLength==0)return -1;
    
    // if len(needle) > len(haystack) return -1;
    if(needleLength>haystackLength)return -1;
    
    char *itr = haystack;
    char *itrN = needle;
    
    while(*itr!='\0')
    {
        if(*itr==*itrN)
        {
            firstIndex=i;
            subStrLen++;
            for(j=1;j<needleLength;j++)
            {
                if((firstIndex+j)<haystackLength && (haystack[firstIndex+j] == needle[j]))
                {
                    subStrLen++;
                }
                
            }
            
            if(subStrLen==needleLength)
            {
                return firstIndex;
            }
            else
            {
                subStrLen=0;
            }
            
        }
        itr++;i++;
    }
    return -1;
}

