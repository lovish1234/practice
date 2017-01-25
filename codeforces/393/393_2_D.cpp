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
#include<bitset>


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

#define EPS 0.0000001


#define ll long long int

typedef pair<int , int> PI;
typedef vector< int > VI;
typedef vector < vector < int > > VVI;


typedef pair<ll , ll> PL;
typedef vector< int > VL;
typedef vector < vector < ll > > VVL;


/*
 * General Purpose Functions 
 */

int max2(int x,int y)
{
    return  (x>y)?x:y;
}
int min2(int x,int y)
{
    return  (x<y)?x:y;
}
int min3(int x, int y, int z)
{
    return  ((x<y))? ((x<z)?x:z): ((y<z)?y:z);
}
int max3(int x, int y, int z)
{
    return   ((x>y))? ((x>z)?x:z): ((y>z)?y:z);
}


int GCD(int u,int v)
{
	if(v==0)
	{
		return u;
	}
	else
	{
		return GCD(v,u%v);
	}
}

int LCM(int u, int v)
{
	return (u*v)/GCD(u,v);
}


/* Weather a number is prime 
 */
int IsPrime(int u)
{
	fab(i,2,sqrt(u))
	{
		if(!(u%i))
		{
			return 0;
		}
	}
	return 1;
}

/*power of n 
  */
ll power(int n, int p)
{
	ll ans=1;
	while(p>0)
	{
		ans*=n;
	}
	return ans;
}

/* Depth First Search within a Graph
 * Requirements : vector <int> visited
 * 				  vector<int> adj[N]
 */

/*
void DFS(int u)
{
	if(visited[u]==1)
	{
		return;
	}
	else
	{
		visited[u]=1;
		f(i,adj[u].size())
		{
			if(visited[adj[u][i]]==0)
			{
				DFS(adj[u][i]);
			}
		}
	}
}
*/

/* Comparator Function
 */
bool comparator(pair < ll, pair< ll,ll > > const& a, pair < ll, pair< ll,ll > > const& b)
{
	return a.F < b.F;
}

int binarySearch(vector<int> a, int low, int high,int value)
{
	int mid,ans,ohigh=high;
	while(high>low)
	{
		mid=low+(high-low)/2;
		//debug3(low,high,mid);
		if(a[mid]>value)
		{
			if(mid==1 || (a[mid-1]<=value))
			{
				ans=mid;
				break;
			}
			else
			{
				high=mid;
			}
		}
		else if(a[mid]<value)
		{
			if(mid==high || a[mid+1]>value)
			{
				ans=mid+1;
				break;
			}
			else
			{
				low=mid;
			}
		}
		else
		{
			ans=mid+1;
			break;
		}
	}
	//debug2(ohigh,ans);
	return (ohigh-ans+1);
}

int main()
{
	int n,temp,rides_90,rides_1440;
	vector<int> a;
	a.pb(-1500);
	cin >> n;
	int dp[n];
	f(i,n)
	{
		cin >> temp;
		a.pb(temp);
	}

	dp[0]=0;
	dp[1]=20,dp[2]=40;
	fab(i,3,n)
	{
		rides_90=binarySearch(a,1,i,a[i]-90);
		rides_1440=binarySearch(a,1,i,a[i]-1440);
		dp[i]=min3(20+dp[i-1],50+dp[i-rides_90],120+dp[i-rides_1440]);
	}
	
	fab(i,1,n)
	{
		debug(dp[i]-dp[i-1]);
	}

	return 0;
}
