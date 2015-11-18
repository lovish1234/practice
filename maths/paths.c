/**
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output Integer
 */
 
long long int factorial(int A)
{
    if(A==0)
    {
        return 1;
    }
    int i;
    long long result=1;
    for(i=1;i<=A;i++)
    {
        result*=i;
        //printf("%d\n",result);
    }
    
    
    return result;
}

long long int divFactorial(int A, int B)
{
    if(B==0)
    {
        return 1;
    }
    int i;
    long long int result=1;
    for(i=A+1;i<=A+B;i++)
    {
        result*=i;
        //printf("%d %lli\n",i,result);
    }
    
    return result;
}

int uniquePaths(int A, int B) {
    long long int result;
    if(A>B)
    {
        result = divFactorial(A-1,B-1)/factorial(B-1);
        //printf("%d\n",divFactorial(A-1,B-1));
    }
    else
    {
        result = divFactorial(B-1,A-1)/factorial(A-1);
    }
    
    //printf("%d\n",result);
    return result;
}
