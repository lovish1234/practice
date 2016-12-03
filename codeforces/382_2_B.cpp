#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;

int comparator( const void *a, const void *b )
{
	return ( *(int*)b - *(int*)a );
}

int main()
{
	int n,n1,n2,i;
	scanf("%d %d %d",&n,&n1,&n2);
	int array[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	qsort(array,n,sizeof(int),comparator);
    

	int g1 = (n1>n2)?n2:n1;
	int g2 = (n1>n2)?n1:n2;
    
	long long int sum1=0,sum2=0;
	for(i=0;i<g1;i++)
	{
		sum1+=array[i];
	}
	for(int j=0;j<g2;j++,i++)
    {
		sum2+=array[i];
	}

	long double t1 = (long double)sum1/(long double)g1;
	long double t2 = (long double)sum2/(long double)g2;
    double ans = t1+t2;
    printf("%.101f\n",ans);
	return 0;
}
