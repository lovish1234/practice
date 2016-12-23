#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<list>

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
	int S,x1,x2;
	sd3(S,x1,x2);

	int t1,t2;
	sd2(t1,t2);

	int p,d;
	sd2(p,d);
    
	if(x1==x2)
	{
		cout << 0;
		return 0;
	}
	int walkingtime = t2*abs(x2-x1);
    int tramtime = 0;
	if( d==1 )
	{
		if(x2<x1)
		{
			tramtime = (S-p)*t1+(S-x2)*t1;
		}
		else
		{
			if(p <= x1 && p < x2)
			{
				tramtime = (x2-p)*t1;
			}
			else
			{
				tramtime = (S-p)*t1+(S+x2)*t1;
			}
		}
	}
	else
	{
		if(x2>x1)
		{
			tramtime = p*t1+x2*t1;
		}
		else
		{
			if( p>=x1 && p>x2)
			{
				tramtime = (p-x2)*t1;
			}
			else
			{
				tramtime = p*t1 + S*t1 + (S-x2)*t1;
			}
		}
	}
	int ans = (tramtime>walkingtime)?walkingtime:tramtime;
	cout << ans;
	return 0;

}
