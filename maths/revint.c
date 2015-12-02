/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int reverse(int A) 
{
    int numDigits=0,sign=1,i,temp=A;
    long long int ans=0;
    // Apart from this case it may be possible that input fits the 32 bit integer
    // but output does not fit. eg. -1170064042,  -1146467285, easiest approach is 
    // to assume answer as long long int and cas it to int while returning 
    if(A<0)
    {
        sign=0;
        A=-A;
        //printf("Negetive  %d\n",A);
    }
    while(A)
    {
        numDigits++;
        A/=10;
    }
    for(i=0;i<numDigits;i++)
    {
        ans+=pow(10,numDigits-i-1)*(temp%10);
        temp/=10;
    }
    
    if(ans>=INT_MAX || ans<=-INT_MAX)return 0;
    return (int)ans;
}
