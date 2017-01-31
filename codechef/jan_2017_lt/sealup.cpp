#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<utility>

#include<cstring>
#include<string>
#include<list>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<vector>
#include<tuple>
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

#define mt make_tuple
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define pf pop_front


#define EPS 0.0000001


#define ll long long int

typedef pair<int , int> PI;
typedef vector< int > VI;
typedef vector < vector < int > > VVI;


typedef pair<ll , ll> PL;
typedef vector< int > VL;
typedef vector < vector < ll > > VVL;

typedef tuple<int,int,int> TI;

/*
 * General Purpose Functions 
 */

template <typename T>  T max2(T x,T y)
{
    return  (x>y)?x:y;
}
template <typename T> T min2(T x,T y)
{
    return  (x<y)?x:y;
}
template <typename T>  T min3(T x, T y, T z)
{
    return  ((x<y))? ((x<z)?x:z): ((y<z)?y:z);
}
template <typename T> T max3 (T x, T y, T z)
{
    return   ((x>y))? ((x>z)?x:z): ((y>z)?y:z);
}


template <typename T>  T GCD(T u,T v)
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

template <typename T> T LCM(T u, T v)
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

const long long int inf=1e18;
const int N=2000005;
ll dp[N][11];

void call()
{
	int n,m;
	ll x1,x2,y1,y2,fx1,fy1;
	
	// calculating distance between two vertices of polygon
	cin >> n;
	ll d[n];
	cin >> x1 >> y1;
	fx1=x1,fy1=y1;
	f(i,n-1)
	{
		cin >> x2 >> y2;
		if(i==(n-2))
		{
			d[i]=ceil(sqrt(1LL*(x2-x1)*(x2-x1)+1LL*(y2-y1)*(y2-y1)));
			d[i+1]=ceil(sqrt((x2-fx1)*(x2-fx1)+(y2-fy1)*(y2-fy1)));
			break;
		}
		d[i]=ceil(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
		x1=x2,y1=y2;
	}
	/*
	f(i,n)
	{
		debug(d[i]);
	}
	*/
	cin >> m;
	ll c[m],l[m];
	f(i,m)
	{
		cin >> l[i] >> c[i];
	}

	// dp state [d(distance),i(include first i sticks)]-> c(cost)
	// max distance could be 10^6+10^6-1~ 2*10^6
	f(i,m)
	{
		dp[0][i]=0;
	}
	f(j,N)
	{
		dp[j][0]=inf;
	}

	fab(i,1,m)
	{
		fab(j,1,N-1)
		{
			dp[j][i]=dp[j][i-1];
			if(j>=l[i-1])
			{
				// either using the ith length stick or not using it for a
				// certain length of a window
				dp[j][i]=min2(dp[j][i-1],dp[j-l[i-1]][i]+c[i-1]);
			}
		}
	}
/*
	fab(i,1,m)
	{
		fab(j,1,N-1)
		{
			cout << dp[j][i] << " ";
		}
		cout << "\n";
	}
*/

	// as exact length of stick may be greater than required
	fabr(i,N-2,1)
	{
		dp[i][m]=min2(dp[i+1][m],dp[i][m]);
	}
/*	
	fab(i,1,m)
	{
		fab(j,1,N-1)
		{
			cout << dp[j][i] << " ";
		}
		cout << "\n";
	}
*/
	ll ans=0;
	f(i,n)
	{
		ans+=dp[d[i]][m];
	}
	cout << ans;
}

int main()
{
	int t;
	cin >> t;
	while(t>0)
	{
		call();
		t--;
	}
	return 0;
}
