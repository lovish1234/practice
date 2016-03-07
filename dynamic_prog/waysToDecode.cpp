int number_of_strings;

void init()
{
    number_of_strings=0;
}

void decodings(string A)
{
    int size = A.size();
    if(size==0)
    {
        number_of_strings++;
    }
    else if(size==1)
    {
        string str=A.substr(0,1);
        int value=atoi(str.c_str());
        string lookahead=A.substr(1);
        if(value!=0)
        {
            decodings(lookahead);
        }
    }
    else if(size>=2)
    {
        
        string str=A.substr(0,1);
        int value=atoi(str.c_str());
        string lookahead=A.substr(1);
        if(value!=0)
        {
            decodings(lookahead);
        }        
        
        str= A.substr(0,2);
        value= atoi(str.c_str());
        if(value>=10 && value<=26)
        {
            lookahead=A.substr(2);
            decodings(lookahead);
        }
    }
}


int Solution::numDecodings(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
    {
        return 0;
    }
    init();
    decodings(A);
    return number_of_strings;
}
