#include<stdio.h>
#include<stdlib.h>

void Merge( int *array, int begin, int mid, int end)
{
	int i=0,j=mid,k=0;
	int *result = (int *) malloc((end-begin+1) * sizeof(int));
	while ( i< ((mid-1)-begin+1) && j < (end - mid + 1))
	{
		if(array[i] <= array[j])
		{
			result[k]=array[i];
			i++;k++;
		}
		else
		{
			result[k]=array[j];
			j++;k++;
		}
	}
	if(i==((mid-1)-begin+1))
	{
		while(j<(end-mid+1))
		{
			result[k]=array[j];
		}
	}
	if(j==(end-mid)+1)
	{
		while(i< ((mid-1)-begin+1) )
		{
			result[k]=array[i];
		}
	}

	for(k=0;k<(end-begin+1);k++)
	{
		array[begin+k]=result[k];
	}
	free(result);


}
			



void MergeSort( int *array, int begin, int end)
{
	if ( begin<= end + 1)
	{
		return;
	}
	int mid = begin + (( end - begin )/2);

	MergeSort(array, begin, mid -1);
	MergeSort(array, mid, end);
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
		scanf("%d ",&array[j]);
	}
    printf("\n");

	MergeSort(array, 0, i);
    
	for(j=0;j<i; j++)
	{
		printf("%d ",array[j]);
	}
   
}
