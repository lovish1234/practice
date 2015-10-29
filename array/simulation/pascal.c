/**
 * @input A : Integer
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* getRow(int A, int *length_of_array) {
	// SAMPLE CODE
        
         *length_of_array = A+1; // length of result array
         int *result = (int *) malloc((*length_of_array+1) * sizeof(int));
         // DO STUFF HERE
         
         int i,temp,j,temp_swap;
         
         //Initialize the array
         for(i=1;i<= *length_of_array; i++)
         {
             result[i]=0;
         }
         result[0]=1;
         
         // if first row of triangle is asked, return the array
         if(A==0)
         {
             return result;
         }
         
         
         for( i=1; i<=A; i++)
         {
             for( j=0; j<=i; j++)
             {
                 if (j==0)
                 {
                    temp=result[j]; 
                    result[j]+=0;
                    
                 }
                 else
                 {
                    temp_swap = result[j];
                    result[j]+=temp;
                    temp = temp_swap;
                     
                     
                 }
             }
             
         }
         
         return result;
         
}

