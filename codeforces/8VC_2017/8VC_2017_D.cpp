#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

#include<cstring>
#include<string>
#include<list>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
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
typedef pair<ll,ll> P;



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


bool comparator(pair < ll, pair< ll,ll > > const& a, pair < ll, pair< ll,ll > > const& b)
{
	return a.F < b.F;
}


int main()
{
	ll n,k;
	cin >> n >> k;

	if(k>(n/2))
	{
		k=(n-k);
	}
	// starting and ending point
	int a[n];
	f(i,n)
	{
		a[i]=0;
	}

	ll flag=0,i=0,sections=1,intersect=0;
	while(flag==0)
	{
		a[i]+=1;
		a[(i+k)%n]+=1;

		intersect=0;
		for(ll j=1;j<k;j++)
		{
			if((i+j)>=n)
			{
				intersect+=a[(i+j)%n];
			}
			else
			{
				intersect+=a[i+j];
			}
		}
		sections+=(intersect+1);
		i=(i+k)%n;

		cout << sections << " ";
		if(a[0]==2)
		{
			flag=1;
		}
	}
	return 0;
}
