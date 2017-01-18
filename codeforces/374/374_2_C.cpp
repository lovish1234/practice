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

const int N=5005;
vector< pair<int,int> > adj[N];
VI max_path;
//VI temp_paths;


void DFS(int u, ll time, VI temp_paths,int n)
{
	if(adj[u].size()==0)
	{
		if(temp_paths.size()>max_path.size() && temp_paths[temp_paths.size()-1]==(n-1))
		{
			max_path.clear();
			f(i,temp_paths.size())
			{
				max_path.pb(temp_paths[i]);
			}
		}
	}

	f(i,adj[u].size())
	{
		if((time-adj[u][i].S)>=0 )
		{
			temp_paths.pb(adj[u][i].F);
			//debug(temp_paths.size());
			if(temp_paths.size()>max_path.size() && temp_paths[temp_paths.size()-1]==(n-1))
			{
				max_path.clear();
				f(i,temp_paths.size())
				{
					max_path.pb(temp_paths[i]);
				}
			}
		
			DFS(adj[u][i].F,time-adj[u][i].S,temp_paths,n);
			temp_paths.pop_back();
		}
		else
		{
			if(temp_paths.size()>max_path.size() && temp_paths[temp_paths.size()-1]==(n-1))
			{
				max_path.clear();
				f(i,temp_paths.size())
				{
					max_path.pb(temp_paths[i]);
				}
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
	int n,m,temp1,temp2,temp3;
	ll k;
	cin >> n >> m >> k;

//	adj.resize(n);
	f(i,m)
	{
		cin >> temp1 >> temp2 >> temp3;
		adj[temp1-1].pb(mp((temp2-1),temp3));
	}

	VI temp_paths;
	max_path.clear();
	temp_paths.pb(0);
	DFS(0,k,temp_paths,n);

	cout << max_path.size() << "\n";
	f(i,max_path.size())
	{
		cout << max_path[i]+1 << " ";
	}
	
	return 0;
}
