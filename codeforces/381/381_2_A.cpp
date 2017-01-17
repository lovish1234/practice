#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

typedef long long int ll;

int main()
{
	ll n,a,b,c,ans=0;
	scanf("%lld %lld %lld %lld",&n,&a,&b,&c);

	if(n%4==0)
	{
		cout << ans;
		return 0;
	}
	else if (n%4==1)
	{
		ll midans = (3*a>c)?c:3*a;
		ans = ((b+a)>midans)?midans:(b+a);
	}
	else if (n%4==2)
	{
		ll midans = (b>2*a)?2*a:b;
		ll midans1 = (midans>2*c)?2*c:midans;
		ans = ((a+b+c)>midans1)?midans1:(a+b+c);
		
	}
	else 
	{
		ll midans = (a>(b+c))?(b+c):a;
		ans = (3*c>midans)?midans:3*c;
	}
	cout << ans;
	return 0;
}


