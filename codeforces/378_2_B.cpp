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
#define frab(i,b,a) for(int i=b;i>=a;i--)

#define debug(a) cout<< a << "\n"
#define debug2(a,b) cout << a << " " < b << "\n"
#define debug3(a,b,c) cout << a << " " << b << " " << c << "\n"

#define  mz(array)  memset(array,0,sizeof(array))

#define mp make_pair
#define F first
#define S second

#define ll long long int

bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}

int main()
{
	int n;
	cin >> n;
	int diff[n],l,r,sum=0,maxprof=0,index=-1,positive=0,negetive=0;
	f(i,n)
	{
		cin >> l >> r;
		diff[i]=(l-r);
		sum+=diff[i];
		if(diff[i]<0)
		{
			negetive=1;
		}
		if(diff[i]>0)
		{
			positive=1;
		}
	}

	if(positive==0 || negetive==0)
	{
		cout << 0;
		return 0;
	}

	f(i,n)
	{
		maxprof=max(maxprof,abs(sum-2*diff[i]));
		if(maxprof==abs((sum-2*diff[i])))
		{
			index=i;
		}
	}
	if(index==-1)
	{
		cout << 0;
	}
	else
	{
		cout << index+1;
	}

	return 0;
}
