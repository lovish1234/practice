/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
int titleToNumber(char* A) {
    
    int count=0,i=0,value,column=0;
    
    //count the number of characters

    
    while( A[i]!='\0')
    {
        count++;i++;
    }
    
    
    
    for(i=0;i<count;i++)
    {
        value = A[i] - '0';
        //printf("%d\n", value);
        value-=16;
        
        column += value * pow(26, count-i-1);
    }
    
    return column;
}
