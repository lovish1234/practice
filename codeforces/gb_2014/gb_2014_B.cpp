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
	int n;
	sd(n);

	int array[n];
	f(i,n)
	{
		sd(array[i]);
	}

	int flag[n][n];
	f(i,n)
	{
		f(j,n)
		{
			sd(flag[i][j]);
		}
	}

	// connected graph and DFS
	int min=INT_MAX;
	f(i,n)
	{
		min=(min>array[i])?array[i]:min;


	return 0;
}
