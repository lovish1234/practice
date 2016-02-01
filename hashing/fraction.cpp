string Solution::fractionToDecimal(int numerator, int denominator) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // handle the sign first
    
        // result would be of the form Int*[.]Int*
         
        long long int  n = numerator, d = denominator;
        if (!n) return "0";
        string result = "";
        unordered_map<int,int> H;
         
        // handle the sign 
        if (n < 0 ^ d < 0) result += '-';
        n = abs(n), d = abs(d);
         
        // Int* 
        result += to_string(n/d);
        n %= d;
         
        if (n)
        {
            result += '.';
        }
        
        while (n) 
        {
            // if the numenator ie quotient is repeating itself
            if (H.find(n) != H.end()) 
            {
                result.insert(H[n], 1, '(');
                result += ')';
                return result;
            }
                     
            H[n] = result.size();
                     
            n *= 10;
            result += to_string(n / d);
            n %= d;
        }
         
        return result;
    
    
}
