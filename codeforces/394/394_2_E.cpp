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
		p--;
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

const int N=50;
vector<int> visited(N,0);
vector<int> adj[N];
vector<PL> ans;

vector<PI> movement = {{1,0},{0,1},{-1,0},{0,-1}};
void DFS(int root, ll dist, int currDir)
{
	int s=adj[root].size();
	vector<int> dir(4,0);

	int next;
	if(currDir!=-1)
	{
		dir[currDir]=1;
	}

	f(i,s)
	{
		next=adj[root][i];	
		if(visited[next]!=1)
		{
			f(j,4)
			{
				if(dir[j]==0)
				{	
					ans[next].F=ans[root].F+movement[j].F*(dist/2);
					ans[next].S=ans[root].S+movement[j].S*(dist/2);
					
					dir[j]=1;
					visited[next]=1;

					if(j==1) currDir=3;
					if(j==3) currDir=1;
					if(j==0) currDir=2;
					if(j==2) currDir=0;
					break;
				}
			}
			DFS(next,(dist/2),currDir);
		}
	}
}

int main()
{
	int n,u,v,root=0;
	cin >> n;


	set<int> M;
	f(i,n-1)
	{
		cin >> u >> v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}

	f(i,n)
	{
		if(adj[i].size()>4)
		{
			cout << "NO";
			return 0;
		}
	}

	f(i,n)
	{
		ans.pb(mp(-1,-1));
	}
	cout << "YES" << "\n";
	ans[root]=mp(0,0);
	ll dist= power(2,40);
	visited[root]=1;

	
	DFS(root,dist,-1);
	
	f(i,n)
	{
		debug2(ans[i].F,ans[i].S);
	}
	return 0;
}
