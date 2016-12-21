#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

#define sd(a) scanf("%d",&a)
#define sd2(a) scanf("%d%d",&a,&b)
#define sd3(a) scanf("%d%d%d",&a,&b,&c)

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

