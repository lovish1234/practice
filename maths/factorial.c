/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int trailingZeroes(int A) {
    
    // number of times five and two appear till the number as last digits. actully
    // this will be the number of times five appear till the digit.
    if (A==0)
    {
        return 0;
    }
    
    int zero=0,i=1;
    while (i)
    {
        zero+=(A/pow(5,i));
        if(A/pow(5,i))
        {
            i++;
        }
        else
        {
            break;
        }
    }
    return zero;

}
