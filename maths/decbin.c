/**
 * @input A : Integer
 * 
 * @Output string. Make sure the string ends with null character
 */
char* findDigitsInBinary(int A) {
	// SAMPLE CODE
	
    char* result = (char *)malloc(100 * sizeof(char));
	// DO STUFF HERE
	if (A==0)
	{
	    result[0]='0';
	    result[1]='\0';
	    return result;
	}
	
	if (A==1)
	{
	    result[0]='1';
	    result[1]='\0';
	    return result;
	}
	
	int quo, i=0;
	while((A/2) > 0 )
	{
	    if ((A%2)==1)
	    {
	        result[i] = 1 + '0';
	    }
	    else
	    {
	        result[i] = 0 + '0';
	    }
	    //printf("%c",result[i]);
	    i++;
	    A/=2;
	}
	result[i]= 1 + '0';
	result[i+1]='\0';
	
	// reverse the digits
	int j,temp;
	for (j=0;j<((i/2)+1);j++)
	{
	    temp = result[j];
	    result[j] = result[i-j];
	    result[i-j] = temp;
	    
	}
	
    return result; 
	 
	 
	 
}
