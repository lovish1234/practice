/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */

int comparator (const void* a, const void* b)
{
    int value1= *(int*)a;
    int value2= *(int*)b;
    
    if(value1 > value2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    return 0;
}
int threeSumClosest(int* A, int n1, int B) {
    //suppose the array is sorted
    qsort(A,n1,sizeof(int),comparator);
    int sum=0;
    
    // if array consists or 3 numbers or target is less than every element in array
    if(n1==3 || B<A[0])
    {
        return (A[0]+A[1]+A[2]);
    }
    
    // if target is greater than every element of array
    if(B>A[n1-1])
    {
        return (A[n1-1]+A[n1-2]+A[n1-3]);
    }
  
    int i,j,k;
    int iprev=0, jprev=n1-1, kprev=0,sumprev=A[0]+A[1]+A[n1-1], answer;
    // sum is increasing inside these two loops
    for(i=0;i<n1;i++)
    {
        j=n1-1;
        for(k=i+1;k<n1;k++)
        {
            
            // sum is decreasing inside this loop
            for(;j>k;j--)
            {
                if(i!=j && j!=k && k!=i )
                {
                    sum = A[i]+A[j]+A[k];
                    //printf("%d\n",sum);
                    // if sum is exactly equal to target return sum
                    if(sum==B)
                    {
                        return sum;
                    }
                    
                    // when the sum reaches the point where it is less than B 
                    // compare the sum from previous value and break the loop
                    if(sum < B)
                    {
                        if( abs(B-sum) < abs(sumprev-B)  )
                        {
                            answer = sum;
                           // printf("%d %d\n",answer,sum);
                        }
                        else
                        {
                            answer = sumprev;
                        }
                        sumprev = sum;
                        break;
                    }
                        
                    
                    sumprev = sum;
                    
                    
                }
                
                //jprev=j;
            }
            //kprev=k;
        }
        //iprev=i;
    }
    return answer;
}
