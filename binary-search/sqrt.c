/**
 * @input A : Integer
 * 
 * @Output Integer
 */
 
 int numOfDigits(int A)
 {
     int count=0;
     while(A)
     {
         count++;
         A/=10;
     }
     return count ;
 }
 
 int power(int x, int y)
 {
     int i,ans=1;
     for(i=0;i<y;i++)
     {
         ans*=ans*x;
     }
     return ans;
 }
 int maxDig(int num)
 {
     int i,sum;
     for(i=0;i<num;i++)
     {
         sum+=9*power(10,(i+1));
     }
     return sum;
 }
 
 
int Sqrt(int A) {
    if(A==0)
    {
        return 0;
    }
    int low=1, high=A, mid;
    long long int temp;
    
    // try to find a good seed value ( initial estimation ) of square root
    
    while(low<=high)
    {
        mid=low+(high-low)/2;
        temp = mid*mid;
        if(temp < A && (temp + 2*mid + 1) > A)
        {
            return mid;
        }
        else if( temp >= A)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
}

