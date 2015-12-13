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
  
    int i,j,k,sum=0;
    int  answer= A[n1-3]+A[n1-2]+A[n1-1] ;
    int min =INT_MAX;
    // sum is increasing inside these two loops
    for(i=0;i<n1;i++)
    {
        j=n1-1;
        k=i+1;
        while( j>k )
        {
            
            // sum is decreasing inside this loop
            
            sum = A[i]+A[j]+A[k];
                    
                    // if sum is exactly equal to target return sum
            if(sum==B) return sum;
            //printf("%d\n",sum);        
                    // when the sum reaches the point where it is less than B 
                    // compare the sum from previous value and break the loop
                    //printf("%d\n", sum);
            //printf("%d %d %d %d\n",i,j,k,sum);
            if (abs(B-sum)<min)
            {

                answer=sum;
                min=abs(B-sum);

            }
            //answer = (abs(answer) < abs(B-sum)) ? answer : sum;
            if(sum < B) k++;
            if(sum > B) j--;
          
           
        }
    }
    return answer;
}
