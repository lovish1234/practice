#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

#include<string>
#include<list>
#include<queue>
#include<unordered_map>
#include<unordered_set>


using namespace std;

#define sd(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define fr(n,i) for(int i=(n-1);i>=0;i--)
#define fabr(i,b,a) for(int i=b;i>=a;i--)

#define debug(a) cout<< a << "\n"
#define debug2(a,b) cout << a << " " << b << "\n"
#define debug3(a,b,c) cout << a << " " << b << " " << c << "\n"

#define  mz(array)  memset(array,0,sizeof(array))

#define mp make_pair
#define F first
#define S second
#define pb push_back

#define ll long long int

// need a general max and min function in template

bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}

int main()
{
	ll b,d,k,m;
	cin >> b >> d >> k;

	if(b>d)
	{
		if(b>k)
		{
			m=b;
		}
		else
		{
			m=k;
		}
	}
	else
	{
		if(d>k)
		{
			m=d;
		}
		else
		{
			m=k;
		}	
	}

	vector<ll> A;
	A.pb(b);
	A.pb(d);
	A.pb(k);
//	cout << m << "\n";
	ll ans=0;
	f(i,3)
	{
//		cout << A[i] << "\n";
		if((A[i]-m+1)<0)
		{
			ans+=(m-1-A[i]);
//			cout << ans << "\n";
		}
	}
	cout << ans;
	return 0;
}
