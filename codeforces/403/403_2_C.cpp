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
#define MOD 1000000007

#define ll long long int

typedef pair<int , int> PI;
typedef vector< int > VI;
typedef vector < vector < int > > VVI;


typedef pair<ll , ll> PL;
typedef vector< ll > VL;
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
template<typename T> T power(T u,T v)
{
	T ans=1;
	while(v>0)
	{
		if(v%2==1) 
			ans=(ans*u);
		v/=2;
		u=(u*u);
	}
	return ans;
}

/* Depth First Search within a Graph
 * Requirements : vector <int> visited
 * 				  vector<int> adj[N]
 */


const int N=200005;
VI adj[N];
VI color;


void DFS(int u, int v)
{	
		int current=1;
		// assign a color
		f(i,adj[u].size())
		{
			if(color[adj[u][i]]==0)
			{
				while(color[u]==current || color[v]==current)
				{
					current++;
				}
				color[adj[u][i]]=current++;
				DFS(adj[u][i],u);
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
	int n,temp1,temp2;
	cin >> n;

	int a[n+1];
	f(i,n+1)
	{
		a[i]=0;
		color.pb(0);
	}

	f(i,n-1)
	{
		cin >> temp1 >> temp2;
		a[temp1]++;
		a[temp2]++;
		adj[temp1].pb(temp2);
		adj[temp2].pb(temp1);
	}
	int max_a=INT_MIN;
	f(i,n+1)
	{
		max_a=max2(max_a,a[i]);
	}
	cout << max_a+1 << "\n";

	// parent node, grand parent node
	color[1]=1;
	DFS(1,1);
	
	fab(i,1,n)
	{
		cout << color[i] << " ";
	}
	return 0;
}
