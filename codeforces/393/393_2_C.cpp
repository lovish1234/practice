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

/* Depth First Search within a Graph
 * Requirements : vector <int> visited
 * 				  vector<int> adj[N]
 */


const int N=200005;
int visited[N];
vector<int> adj[N];
vector<int> temp_component;
vector< vector<int> > component;

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



/* Comparator Function
 */
bool comparator(pair < ll, pair< ll,ll > > const& a, pair < ll, pair< ll,ll > > const& b)
{
	return a.F < b.F;
}


int main()
{
	int n;
	cin >> n;
	int b[n];

	int temp;
	f(i,n)
	{
		cin >> temp;
		adj[i+1].pb(temp);
		adj[temp].pb(i+1);
	}

	int one=0,reverse=0;
	f(i,n)
	{
		cin >> b[i];
		if(b[i]==1)
		{
			one++;
		}
	}
	if(one%2==0)
	{
		reverse=1;
	}

	f(i,n)
	{
		if(visited[i+1]==0)
		{
			temp_component.clear();
			DFS(i+1);
			component.pb(temp_component);
		}
	}
	cout << (component.size()>1?component.size():0)+reverse;

	return 0;
}
