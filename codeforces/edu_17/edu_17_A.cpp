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


int main()
{
	ll n;
	int k,j=0;
	cin >> n >> k;
	ll s = sqrt(n),x,nf,cf;

	// get the number of factors
	fab(i,1,s)
	{
		if(!(n%i))
		{
			j++;
		}
	}
	if( (s*s)==n )
	{
		nf=2*j-1;
		cf=j;
		if(k>nf)
		{
			cout << "-1";
		}
		if(k>cf)
		{
			j=0;
			fab(i,1,s)
			{
				if(!(n%i))
				{
					j++;
					if(j==(2*cf-k))
					{
						cout << n/i;
					}
				}
			}
		}
		else
		{
			j=0;
			fab(i,1,s)
			{
				if(!(n%i))
				{
					j++;
					if(j==k)
					{
						cout << i;
					}
				}
			}
		}
	}
	else
	{
		nf=2*j;
		cf=j;
		if(k>nf)
		{
			cout << "-1";
		}
		if(k>cf)
		{
			j=0;
			fab(i,1,s)
			{
				if(!(n%i))
				{
					j++;
					if(j==(nf-k+1))
					{
						cout << n/i;
					}
				}
			}
		}
		else
		{
			j=0;
			fab(i,1,s)
			{
				if(!(n%i))
				{
					j++;
					if(j==k)
					{
						cout << i;
					}
				}
			}
		}
	}
	return 0;
}
