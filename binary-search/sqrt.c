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
 
 int findSeed(int A)
 {
     int count=0;
     while(A/100)
     {
         count+=1;
         A/=100;
     }
     
     if(A>10)
     {
         return 6*pow(10,count);
     }
     else
     {
         return 2*pow(10,count);
     }
     
 }
 
int Sqrt(int A) {
    if(A==0)
    {
        return 0;
    }
    
    if(A==3)
    {
        return 1;
    }
    double limit1=findSeed(A), limit2=A/limit1;
    int count=0;
    double low=limit1>limit2?limit2:limit1;
    double high=limit1>limit2?limit1:limit2;
    double prevmid = low + (high-low)/2, mid=0.0, temp;
    int prevmidint = (int)prevmid, midint = (int)mid;
    
    //printf("%d %d %d \n", low, high, prevmid);
    // try to find a good seed value ( initial estimation ) of square root
    
    
    while((int)midint!=(int)prevmidint)
    {
       mid=(prevmid+(A/prevmid))/2;
       prevmid=(mid+(A/mid))/2;
       prevmidint = (int)prevmid;
       midint = (int)mid;
    }
    
    return midint;
}

