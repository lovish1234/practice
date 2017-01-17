#include<cstdio>
#include<iostream>
#include<cmath>

#include<string>
#include<list>
#include<queue>
#include<unordered_map>

using namespace std;

#define sd(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define f(i,n) for(int i=0;i<n;i++)
#define fl(i,a,b) for(int i=a;i<=b;i++)

#define  mz(array)  memset(array,0,sizeof(array))

#define mp make_pair

#define ll long long int

int main()
{
	int n,m;
	sd2(n,m);

	int array[n];
	int sum[n][n];
	f(i,n)
	{
		sd(array[i]);
	}

	f(i,n)
	{
		sum[i][i]=array[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			sum[i][j]=sum[i][j-1]+array[j];
		}
	}
	int ans=0,l,r;
	f(i,m)
	{
		sd2(l,r);
		if(sum[l-1][r-1]>0)
		{
			ans+=sum[l-1][r-1];
		}
	}
	cout << ans;
	return 0;
}
