/**
 * @input A : Integer
 * 
 * @Output Integer
 */
 
unsigned  int power(int x, int y)
{
    int i;
    unsigned int ans=1;
    for(i=0;i<y;i++)
    {
        ans*=x;
    }
    return ans;
}
 
unsigned int reverse(unsigned int A) {
    int bitArray[32],i;
    unsigned int ans=0;
    for(i=0;i<32;i++)
    {
        bitArray[i]=0;
    }
    
    i=0;
    while(A)
    {
        bitArray[i]=(A%2);
        i++;
        A/=2;
    }
    
    for(i=0;i<32;i++)
    {
        if(bitArray[i]==1)
        {
            ans=ans+power(2,31-i);
            //printf("%u %u\n",power(2,31-i),ans);
        }
    }
    
    return ans;
}
