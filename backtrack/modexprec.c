/**
 * @input A : Integer
 * @input B : Integer
 * @input C : Integer
 * 
 * @Output Integer
 */
 
long long int recMod(A,B,C)
{
    long long int temp=0;
    if(A<0)
    {
        if(B%2!=0)
        {
            A+=C;
        }
        else
        {
            A=-1*A;
        }
    }
    
    if(B==0)
    {
        return 1;
    }
    
    if(B%2==0)
    {
        temp=recMod(A,(B/2),C) * recMod(A,(B/2),C);
       
    }
    else
    {
        temp=recMod(A,(B-1),C)%C * A%C;
        
    }
    
    return temp%C;
}
 
int Mod(int A, int B, int C) {
    
    if(B==0)
    {
        if(A==0)
        {
            return 0;
        }
        return 1;
    }
    
    if(A==0)
    {
        return 0;
    }
    
   
    return (int)recMod(A,B,C);
}

