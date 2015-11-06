#include<stdio.h>
#include<stdlib.h>

void Merge( int *array, int begin, int mid, int end)
{
	int i=begin,j=mid+1,k=0;
	int *result = (int *) malloc((end-begin+1) * sizeof(int));
    
    

 	while ( i< ((mid)+1) && j < (end + 1))
	{
		if(array[i] <= array[j])
		{
			result[k]=array[i];
//			printf("Replacing result[%d] for array[%d]\n",k,i);

			i++;k++;
		}
		else
		{
			result[k]=array[j];
//			printf("Replacing result[%d] for array[%d]\n",k,j);

			j++;k++;
		}
	
	}
	if(i==(mid+1))
	{
		while(j<(end+1))
		{
			result[k]=array[j];
//			printf("Replacing result[%d] for array[%d]\n",k,j);
			j++;k++;
		}
	
	}
	if(j==(end+1))
	{
		while(i< (mid+1) )
		{
			result[k]=array[i];
//			printf("Replacing result[%d] for array[%d]\n",k,i);

			i++;k++;
		}
	}

	for(k=0;k<(end-begin+1);k++)
	{
		array[k+begin]=result[k];
	}

    free(result);
    return;

}
			



void MergeSort( int *array, int begin, int end)
{

    

	if (end<=begin)
// Remember to think simply and avoid killing a bee by bomb		
//	if (((end-begin) + 1) < 2 )
	{
		return;
	}
	int mid = begin + (( end - begin )/2);

	MergeSort(array, begin, mid );
	MergeSort(array, mid+1, end);
	Merge(array, begin, mid, end );
}


void main()
{
	int i;
	printf("Enter the length of array\n");
    scanf("%d\n",&i);

	int j,array[i];
	for(j=0;j<i;j++)
	{
		scanf("%d",&array[j]);
	}

 //   printf("%d\n\n",i);
   
	MergeSort(array, 0, (i-1));
    
	for(j=0;j<i; j++)
	{
		printf("%d ",array[j]);
	}
    return 0; 
}
