#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ss(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)

int main()
{
	int n,count=1,f1,f2;
	sc(n);
	queue<int> Q1,Q2;
	char x;

	for(int i=0;i<n;i++)
	{
		cin >> x;
		if(x=='D')
		{
			Q1.push(count);
		}
		else
		{
			Q2.push(count);
		}
		count++;
	}

	while( !Q1.empty() && !Q2.empty() )
	{
		f1 = Q1.front(), f2=Q2.front();
		Q1.pop();Q2.pop();
		if( f1 < f2 )
		{
			Q1.push(f1+n);
		}
		else
		{
			Q2.push(f2+n);
		}
	}

	if(Q1.empty())
	{
		cout << "R";
	}
	else
	{
		cout << "D";
	}



	return 0;
}
