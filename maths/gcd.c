/**
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output Integer
 */
int gcd(int A, int B){ 
    if(A==0 )
    {
        return B;
    }
    if(B==0)
    {
        return A;
    }
    int m,i;
    m=(A>B)?B:A;
    for(i=m;i>=1;i--)
    {
        
        if(A%i==0 && B%i==0)
        {
            return i;
            
        }
    }
}
