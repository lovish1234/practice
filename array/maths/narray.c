/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* repeatedNumber(const int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
        
          *length_of_array = 2; // length of result array
          int *result = (int *) malloc(*length_of_array * sizeof(int));
          // DO STUFF HERE
          
         /*
         int i;
         for(i=0;i<n1;i++)
         {
             A[((A[i]%(n1+1))-1)]+=(n1+1);
         }
         
         for(i=0;i<n1;i++)
         {
             if(A[i]/(n1+1)==2)
             {
                 result[0]=A[i];
             }
             
             if(A[i]/(n1+1)==0)
             {
                 result[1]=A[i];
             }
             
         }
         */
         
         int i;
         long long int sum=0,sumsq=0;
         for(i=0;i<n1;i++)
         {
             sum+=A[i];
             sum-=(i+1);
             
             sumsq+=(long long int)A[i]*(long long int)A[i];
             sumsq-=(long long int)(i+1)*(long long int)(i+1);
             
             
         }
         
         sumsq/=sum;
         
         int A1= (sumsq+sum)/2;
         int B1= (sumsq-A1);
         
         result[0]=A1;
         result[1]=B1;
         
         return result;
}
