/**
 * @input A : Integer
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* allFactors(int A, int *length_of_array) {
	// SAMPLE CODE
        
         
         // DO STUFF HERE. NOTE: length_of_array is inaccurate in this example. 
         if (A==0)
         {
             *length_of_array = 1; // length of result array
             int *result = (int *) malloc(*length_of_array * sizeof(int));
             result[0]=0;
             return result;
         }
         
         if (A==1)
         {
             *length_of_array = 1; // length of result array
             int *result = (int *) malloc(*length_of_array * sizeof(int));
             result[0]=1;
             return result;
         }
         
         
         
         
         int i,j=0;
         //printf("H");
         for (i=1;i<=sqrt(A);i++)
         {
             //printf("A");
             if ((A%i)==0 )
             {
                 if (i!=sqrt(A))
                 {
                     j+=2;
                 }
                 else
                 {
                     j+=1;
                 }
                 
             }
            
             
         }
         //printf("%d",j);
         *length_of_array = j; // length of result array
         int *result = (int *) malloc(*length_of_array * sizeof(int));
         j=0;
         for(i=1;i<=sqrt(A);i++)
         {
             if((A%i)==0)
             {
                 if(i!=sqrt(A))
                 {
                     result[j]=i;
                     j++;
                     result[j]=(A/i);
                     j++;
                 }
                 else
                 {
                     result[j]=i;
                     j++;
                 }
                     
             }
         }
         
         *length_of_array = j; // length of result array
         int *resultf = (int *) malloc(*length_of_array * sizeof(int));
         // if j is even, implies it is not a perfect square
         // if j is odd, the last entry would be its square root.
         int k=0;
         for(i=0;i<j;i++)
         {
             if((i%2)==0)
             {
                 resultf[k]=result[i];
                 k++;
             }
         }
         for(i=j-1;i>=0;i--)
         {
             if((i%2)==1)
             {
                 resultf[k]=result[i];
                 k++;
             }
         }
         return resultf;
        
}
