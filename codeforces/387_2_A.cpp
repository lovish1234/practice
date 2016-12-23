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

#define ll long long int

int main()
{
	int n;
	sd(n);

	int root = sqrt(n);
	int i=root,j=root,product;

	while(i>=1 && j<=n)
	{
		product=i*j;
		if(product==n)
		{
			cout << i << " " << j << "\n";
			return 0;
		}
		else if(product<n)
		{
			j++;
		}
		else if(product>n)
		{
			i--;
		}
	}
	return 0;

}
