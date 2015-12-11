/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int removeDuplicates(int* A, int n1) {
    
    int i,j,dup=0,currentdup=0;
    for(i=0;i<(n1-1);i++)
    {
        j=i+1;
        
        if(A[i]==A[j])
        {
            currentdup++;
            //printf("%d \n",currentdup);
            if(currentdup==1)
            {
                A[j-dup]=A[j];
                dup--;
                //printf("%d %d %d\n",j,dup,offset);
            }
          
            dup++;
        }
        else
        {
            
            
            A[j-dup]=A[j];
            
            currentdup=0;
           
        }
    }
    
    for(i=0;i<(n1-dup-1);i++)
    {
        j=i+1;
        if(A[j]<A[i])
        {
            A[j]=A[i];
        }
    }
    //printf("%d %d\n",dup,offset);
    return (n1-dup);
}
