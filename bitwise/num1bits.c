/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int numSetBits(unsigned int A) {
    int count=0,i;
    while(A)
    {
        if(A%2==1)
        {
            count++;
        }
        A/=2;
    }
    return count;
}
