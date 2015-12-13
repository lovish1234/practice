/**
 * @input A : Integer
 * 
 * @Output string. Make sure the string ends with null character
 */
char* convertToTitle(int A) {

     int i=0,B=A,value,j;
     while(A>0)
     {
         
         A-=pow(26,i+1);
         i++;
     }
	 //printf("%d\n",i);
	 
	 char *result = (char*)malloc(sizeof(char)*(i+1));
	 result[i]='\0';
	 
	 
     for(j=i;j>0;j--)
     {
         value = ((B-1)%26);
         result[j-1]=value+'A';
         //printf("%d\n",value);
         B--;
         B/=26;
     }
	 
	 
	
	 // know the power of i and A
	 return result;
}
