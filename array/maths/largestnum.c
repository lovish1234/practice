#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int numberOfDigits(int A)
{
    if(A==0)
    {
        return 1;
    }
    
    int i=0;
    while(A)
    {
        i++;
        A/=10;
    }
    return i;
}


// Initially I thought of a complex but bs approach of solving this. But it
// fails in cases such as [27,271] 
/*
int maxIndex(int *A, int n1)
{
    int i,max=-1,maxI=0;
    for(i=0;i<n1;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
            maxI=i;
        }
    }
    return maxI;
}


char* largestNumber(const int* A, int n1) 
{
    int i,maxDigits=0;
    int *digitsNum = (int*)malloc(sizeof(int)*n1);
    
    
    for(i=0;i<n1;i++)
    {
        printf("%d ",A[i]);
    }
    
    
    
    
    for(i=0;i<n1;i++)
    {
        digitsNum[i] = numberOfDigits(A[i]);
        if ( digitsNum[i] > maxDigits)
        {
            maxDigits = digitsNum[i];
        }
        printf("%d ",digitsNum[i]);    
    }
    printf("\n %d",maxDigits);
    
    
}
*/


int compareFunction(const void* a, const void* b) 
{
        int value1 = *((int *)a);
        int value2 = *((int *)b);
        
        int dig1 = numberOfDigits(value1);
        int dig2 = numberOfDigits(value2);
        
		int pow1 = pow(10,dig2);
		int pow2 = pow(10,dig1);
        int value3 = value1 * pow1 + value2;
        int value4 = value2 * pow2 + value1;
        
        if (value3 < value4) {
            // Return -1 if you want ascending. 1 if you want descending. 
            return 1;
        } else if (value3 > value4) {
            // Return 1 if you want ascending. -1 if you want descending. 
            return -1;
        }
        return 0;
}

int nullArray(int *A, int n1)
{
    int i;
    for(i=0;i<n1;i++)
    {
        if(A[i]!=0)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    const int A[]={450,56,10,2,23,20,21,0}; 
	int n1=8;
	int i;

	int *B=(int*)malloc(sizeof(int)*n1);
    int *BL=(int*)malloc(sizeof(int)*n1);

    for(i=0;i<n1;i++)
	{
		B[i]=A[i];
	}
	
    if(nullArray(B,n1))
    {
        char *C = "0\0";
        return C;
    }
    qsort(B, n1, sizeof(int), compareFunction);
//	qsort(B, n1, sizeof(int),compareFuntion);
	
	int length=0,temp,lengthCurrent=0;
	for(i=0;i<n1;i++)
	{
		temp=B[i];
		lengthCurrent=0;
		while(temp)
		{
			length++;lengthCurrent++;
			temp/=10;
		}
		BL[i] = lengthCurrent;
	}

	char *C = (char*)malloc(sizeof(char)*(length+1));
    int j=0,prevLength=0;

	for(i=0;i<n1;i++)
	{
		j=0;
		while(B[i])
		{
			
			C[BL[i]+prevLength-1-j]=(B[i]%10)+'0';
			B[i]/=10;
			j++;
		}

		prevLength+=BL[i];
	}
	C[length]='\0';
    
	for(i=0;i<(length+1);i++)
	{
		printf("%c ",C[i]);
	}


}
