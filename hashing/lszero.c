/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

/*

void fillArray(int **sum, int n1, int i, int j)
{
    if(i==j)
    {
        return sum[i][j];
    }
    else
    {
        return sum[i-1][j]+sum[i][j+1];
    }
}
*/

int* lszero(int* A, int n1, int *len1) {
    
    // a 2D array to store the sum from index i to j
    int** sum=(int**)malloc(sizeof(int*)*n1);
    int i,j,maxLength=INT_MIN,length,minI=INT_MAX;
    int fI,fJ;
    for(i=0;i<n1;i++)
    {
        sum[i]=(int*)malloc(sizeof(int)*n1);
    }
    
    
    for(i=0;i<(n1);i++)
    {
        sum[i][i]=A[i];
        length=1;

        if(sum[i][i]==0 && (maxLength<length) && (minI>=i))
        {
            minI=i;
            fI=i;
            fJ=i;
        }
    }
    
    
    for(i=0;i<n1;i++)
    {
        for(j=i+1;j<n1;j++)
        {


            sum[i][j]=sum[i][j-1]+sum[j][j];
            length=abs(j-i+1);

            //printf("%d %d %d %d\n",i,j,sum[i][j],length);

            if(sum[i][j]==0)
            {
                if(maxLength<length)
                {   
                    //printf("%d %d %d %d \n",i,j,sum[i][j],length);
                    minI=i;
                    fI=i;
                    fJ=j;
                    maxLength=length;
                }
                else if(maxLength==length)
                {
                    if(minI>=i)
                    {
                        //printf("%d %d %d %d \n",i,j,sum[i][j],length);
                        minI=i;
                        fI=i;
                        fJ=j;
                        maxLength=length;
                    }
                }
                
            }
        }

    }
    
    *len1=(fJ-fI+1);
    int *result=(int*)malloc(sizeof(int)*(*len1));
    if(maxLength==INT_MAX)
    {
        return result;
    }
    for(i=0;i<(*len1);i++)
    {
        result[i]=A[fI+i];
    }
    return result;
    
}

