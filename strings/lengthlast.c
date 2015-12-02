/**
 * @input A : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
int lengthOfLastWord(const char* A) {
    int numOfSpaces=0, lastWordStart=0, lastWordLength=0,lastWordStartCounter=0,lastWordLengthCounter=0;
    int count=0;
    char *itr= A;
    while((*itr)!='\0')
    {
        
        if(*itr!=' ')
        {
            if(lastWordLengthCounter==0)
            {
                lastWordStart=lastWordStartCounter;
            }
            lastWordLengthCounter++;
            lastWordLength = lastWordLengthCounter;
        }
        else
        {
            lastWordLengthCounter=0;
        }
        lastWordStartCounter++;
        itr++;
    }
    
    
    //printf ("%d\n",numOfSpaces);
    
    
    /*
    itr=A;
    if (numOfSpaces==0) return lengthFirstWord;
    while(*itr!='\0')
    {
        if(*itr==' ')
        {
            numOfSpaces--;
      //      printf ("%d\n",numOfSpaces);
        }
        if(numOfSpaces==0)
        {
            length++;
        }
        itr++;
    }
    */
    
    
    return lastWordLength;
}

