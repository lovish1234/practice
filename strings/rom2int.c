/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
 
int value( char A)
{
    int ans;
    if(A=='M')
    {
        ans=1000;
    }
    else if(A=='D')
    {
        ans=500;    
    }
    else if(A=='C')
    {
        ans=100;
    }
    else if(A=='L')
    {
        ans=50;    
    }
    else if(A=='X')
    {
        ans=10;    
    }
    else if(A=='V')
    {
        ans=5;    
    }
    else if(A=='I')
    {
        ans=1;    
    }
    else
    {
        printf("Input is Invalid\n");
    }
    return ans;
}

int strLength(char *A)
{
    char* itr = A;
    int ans=0;
    while(*itr!='\0')
    {
        ans++;
        itr++;
    }
    return ans;
}
int romanToInt(char* A) {
   int i,ans=0;
   int length = strLength(A);
   //printf("%d ",length);
   for(i=0;i<(length-1);i++)
   {
       if(value(A[i])<value(A[i+1]))
       {
           ans-=value(A[i]);
       }
       else
       {
           ans+=value(A[i]);
       }
   }
   ans+=value(A[length-1]);
   return ans;
}

