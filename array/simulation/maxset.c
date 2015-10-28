/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in length_of_array
 */
int* maxset(int* A, int n1, int *length_of_array) {
    /*
     * Sample Code : 
     *  *length_of_array = 1;
     *  int * ret = (int *) malloc(sizeof(int) * *length_of_array);
     *  ret[0] = 1;
     *  return ret;
     */
     
     int i;
     int maxsum=0,maxlength=0,maxindex;
     for (i=0;i<n1;i++)
     {
         int j=0,sum=0,length=0,index;
         
         while(A[i]>=0 && i<n1)
         {
             if (j==0)
             {
                 index=i;
             }
             sum+=A[i];
             i++,length++;j++;
         }
         
         if (sum >= maxsum)
         {
             maxsum=sum;
             maxindex=index;
             maxlength=length;
         }
         else if (maxsum==sum)
         {
             if(maxlength < length)
             {
                 maxsum=sum;
                 maxindex=index;
                 maxlength=length;
                 
             }
             
         }
       
     }
     
     *length_of_array=maxlength;
     int * ret = (int *) malloc(sizeof(int) * *length_of_array);
     for (i=0;i<maxlength;i++)
     {
         ret[i]=A[maxindex+i];
     }
     return ret;
}
