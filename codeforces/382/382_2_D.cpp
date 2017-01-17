#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)

int IsPrime(int a1)
{
	for(int i=2;i*i<=a1;i++)
	{
		if(a1%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int N, prevN=0, ans=0, sum=0;
	sc(N);
	if(IsPrime(N))
	{
		cout << "1";
		return 0;
	}

	if(!(N%2))
	{
		cout << "2";
	}
	else
	{
		if(IsPrime(N-2))
		{
			cout << "2";
		}
		else
		{
			cout << "3";
		}
	}
	
	return 0;
}
