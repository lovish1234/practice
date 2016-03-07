#define MAX_INDEX 1000000
int X[MAX_INDEX];
void init()
{
    for(int i=0;i<MAX_INDEX;i++)
    {
        X[i]=0;
    }
}


int Solution::canJump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   int next = A.size() - 1;  
   for (int i=A.size()-2; i>=0; --i) {   
     if (A[i] >= (next - i)) {   
       next = i;   
     }  
   }   
   return (next == 0);  
}
