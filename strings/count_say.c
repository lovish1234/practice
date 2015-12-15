/**
 * @input A : Integer
 * 
 * @Output string. Make sure the string ends with null character
 */
 
int strLength(char* A)
{
    int count=0;
    char* itr=A;
    while(*itr!='\0')
    {
        count++;
        itr++;
    }
    return (count+1);
}

int lengthOfNextTerm( char* term, int length )
{
    char* itr=term;
    int rep=0,i,prev=term[0];
    for(i=1;i<(length-1);i++)
    {
        if(term[i]!=prev)
        {
            rep++;
            
        }
        prev=term[i];
    }
    return (length+rep+1);
}

char* NextTerm(char* P, int P_length, int N_length)
{
    char *N =(char*)malloc(sizeof(char)*N_length);
    char* itr=N;
    int rep=1,i,prev=P[0];
    for(i=1;i<(P_length-1);i++)
    {
        if(P[i]!=prev)
        {
            *itr=rep+'0';
            *itr++;
            *itr=prev;
            itr++;
                
            rep=1;
                
        }
        else
        {
               
            rep++;
        }
        prev=P[i];
    }
    *itr=rep+'0';
    *itr++;
    *itr=prev;
    *itr++;
    *itr='\0';
    return N;
}

char* countAndSay(int A) 
{
   int P_length,N_length,i;    
   char *P = (char*)malloc(sizeof(char)*(1+1));
   P[0]='1',P[1]='\0';
   char*N;
   
   if(A==1)
   {
       return P;
   }
   
   for(i=1;i<A;i++)
   {
       P_length=strLength(P);
       N_length=lengthOfNextTerm(P,P_length);
       //printf("%d %d \n",P_length,N_length);
       //char*N =(char*)malloc(sizeof(char)*N_length);
       N=NextTerm( P, P_length, N_length);
       P=N;
        
   }
   
   
   return P;
}
