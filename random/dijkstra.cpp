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
    return  ((x<y)?x:y)? ((x<z)?x:z): ((y<z)?y:z);
}
int max3(int x, int y, int z)
{
    return   ((x>y)?x:y)? ((x>z)?x:z): ((y>z)?y:z);
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

const int N=1000;


VI visited(N,0);
priority_queue <PI, vector<PI>, greater<PL> > PQ[N];

int main()
{
	int n,m,k,temp1,temp2,temp3;
	cin >> n >> m >> k;
	
	VI previous(n,-1);

	VI dist(n,INT_MAX);
	dist[k-1]=0;

	// (weight, vertex) 
	set< pair<int,int> > M;
	set< pair<int,int> >::iterator it;

	fab(i,0,n-1)
	{
		if(i==k)
		{
			M.insert(mp(0,k-1));
		}
		else
		{
			M.insert(mp(INT_MAX,i));
		}
	}

	vector< vector<PI> > adj;
	adj.resize(n);
	adj.clear();
	f(i,m)
	{
		cin >> temp1 >> temp2 >> temp3;
		adj[temp1-1].pb(mp(temp2-1,temp3));
		adj[temp2-1].pb(mp(temp1-1,temp3));
	}

	int u,v,v_dist;
	while(M.size()!=0)
	{
		// extract minimum distance vertex u
		it=M.begin();
		u=it->S;
		f(i,adj[u].size())
		{
			v=adj[u][i].F;
			v_dist=adj[u][i].S;
			if(dist[v]>dist[u]+v_dist)
			{
				if(M.find(mp(dist[v],v))!=M.end())
				{
					M.erase(mp(dist[v],v));
				}	
				dist[v]=dist[u]+v_dist;
				M.insert(mp(dist[u]+v_dist,v));
			}
		}
		M.erase(mp(it->F,it->S));
	}

	f(i,n)
	{
		cout << i+1 << " " << dist[i] << "\n";
	}

	return 0;
}
