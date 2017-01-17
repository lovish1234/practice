#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

#define sd(a) scanf("%d",&a)
#define sd2(a) scanf("%d%d",&a,&b)
#define sd3(a) scanf("%d%d%d",&a,&b,&c)

#define f(i,n) for(int i=0;i<n;i++)
#define fl(i,a,b) for(int i=a;i<=b;i++)


#define ll long long int


int main()
{
	int n;
	sd(n);
	if(n==1)
	{
		cout << -1;
		return 0;
	}
	cout << n << " " << n+1 << " " << n*(n+1);
	return 0;
}

