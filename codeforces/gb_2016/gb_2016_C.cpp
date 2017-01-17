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
	int rating[n+1], division[n];
	rating[0]=0;
	int alldiv1=1;
	fab(i,1,n)
	{
		cin >> rating[i] >> division[i-1];
		if(division[i-1]==2)
		{
			alldiv1=0;
		}
	}

	if(alldiv1==1)
	{
		cout << "Infinity" << "\n";
		return 0;
	}

	fab(i,1,n)
	{
		rating[i]=rating[i]+rating[i-1];
	}
	int div2min=INT_MAX, div2max=INT_MIN,div1min=INT_MAX,div1max=INT_MIN;
	f(i,n)
	{
		if(division[i]==1)
		{
			div1min=(div1min>rating[i])?rating[i]:div1min;
			div1max=(div1max<rating[i])?rating[i]:div1max;
		}
		else
		{
			div2min=(div2min>rating[i])?rating[i]:div2min;
			div2max=(div2max<rating[i])?rating[i]:div2max;
		}
	}

	if(div1min<=div2max)
	{
		cout << "Impossible" << "\n";
		return 0;
	}

	
	cout << 1899-div2max+rating[n] << "\n";
	return 0;
}
