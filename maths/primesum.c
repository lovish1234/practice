/**
 * @input A : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* primesum(int A, int *len1) {
    *len1 = 2;
    int *result = (int *) malloc (*len1 * sizeof(int));
    int i;
    for (i=2; i<A;i++)
    {
       
        if (IsPrime(i)==1 && IsPrime(A-i)==1)
        {
           
        
                //printf("A");
                result[0]=i;
                result[1]=A-i;
                return result;
            
        }
    }
    
}

int IsPrime(int i)
{
    int j;
    for (j=2;j<=sqrt(i);j++)
    {
        //printf("%d %d",i,j);
        if(i%j==0)
        {
            //printf("B");
            return 0;
        }
    }
    return 1;
}
