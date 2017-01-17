#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)

int main()
{
	int n;
	sc(n);

	if(n%2==0)
	{
		cout << n/2 << "\n";
		for(int i=0;i<(n/2);i++)
		{
			cout << "2 ";
		}
	}
	else
	{
		cout << n/2 << "\n";
		for(int i=0;i<(n/2)-1;i++)
		{
			cout << "2 ";
		}
		cout << "3";
	}
	cout << "\n";
	return 0;
}
