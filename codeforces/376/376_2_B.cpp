#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

#include<string>
#include<list>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>

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


int max(int x,int y)
{
    return  (x>y)?x:y;
}
int min(int x,int y)
{
    return  (x<y)?x:y;
}
int min3(int x, int y, int z)
{
    return  ((x<y)?x:y)? ((x<z)?x:z): ((y<z)?y:z);
}
int max3(int x, int y, int z)
{
    return   ((x>y)?x:y)? ((x>z)?x:z): ((y>z)?y:z);
}


bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}


int main()
{
	int n;
	cin >> n;

	int a[n];
	f(i,n)
	{
		cin >> a[i];
	}

	int dis,coup;
	f(i,n-1)
	{
		dis=a[i]/2;
		a[i]-=(dis*2);

		if(a[i]==0)
		{
			continue;
		}
		else if(a[i]==1)
		{
			if(a[i+1]==0)
			{
				cout << "NO";
				return 0;
			}
			else
			{
				a[i+1]-=1;
			}
		}
	}

	if(a[n-1]%2==0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}		
		
	return 0;
}
