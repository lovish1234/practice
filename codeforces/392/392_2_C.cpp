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
	ll n,m,x,y,temp1,k,b_x;
	cin >> n >> m >> k >> x >> y;
	ll max_q,min_q,s_q;
	ll quotient,remainder;

	if(n==1|| n==2 || k<n*m)
	{
		quotient=(k/(n*m));
		remainder=(k%(n*m));
		if(remainder==0)
		{
			max_q=quotient;
			min_q=quotient;
			s_q=quotient;
		}
		else
		{
			max_q=quotient+1;
			min_q=quotient;
			if(remainder>=((x-1)*m+y))
			{
				s_q=max_q;
			}
			else
			{
				s_q=min_q;
			}
		}
		debug3(max_q,min_q,s_q);
		return 0;
	}

	quotient=(k/(n*m+(n-2)*m));
	remainder=(k%(n*m+(n-2)*m));
	ll pos=(x-1)*m+y;
	//debug2(quotient,remainder);
	if(remainder<m)
	{
		max_q=2*quotient;
		min_q=(quotient);
		if(pos<=remainder)
		{
			s_q=min_q+1;
		}
		else if(pos>remainder && pos<=m)
		{
			s_q=min_q;
		}
		else if(pos>m && pos<=((n-1)*m))
		{
			s_q=max_q;
		}
		else
		{
			s_q=min_q;
		}
	}
	else if(remainder>m && remainder<=(n-1)*m)
	{
		max_q=2*quotient+1;
		min_q=(quotient);
		if(pos<=m)
		{
			s_q=min_q+1;
		}
		else if(pos>m && pos<=remainder)
		{
			s_q=max_q;
		}
		else if(pos>remainder && pos<=((n-1)*m))
		{
			s_q=max_q-1;
		}
		else
		{
			s_q=min_q;
		}
		
	}
	else if(remainder>((n-1)*m) && remainder<n*m)
	{
		max_q=2*quotient+1;
		min_q=(quotient);
		if(pos<=m)
		{
			s_q=min_q+1;
		}
		else if(pos>m && pos<=((n-1)*m))
		{
			s_q=max_q;
		}
		else if(pos>((n-1)*m) && pos<=remainder)
		{
			s_q=min_q+1;
		}
		else if(pos>remainder)
		{
			s_q=min_q;
		}
	}
	else if(remainder==(n*m))
	{
		min_q=(quotient)+1;
		max_q=2*quotient+1;
		if(pos<=m || pos>((n-1)*m))
		{
			s_q=min_q;
		}
		else 
		{
			s_q=max_q;
		}
	}
	else 
	{
		min_q=quotient+1;
		max_q=2*quotient+2;
		if(pos<=m || pos>((n-1)*m))
		{
			s_q=min_q;
		}
		else
		{
			if(((n-x-1)*m+y)<=(remainder-n*m))
			{
				s_q=max_q;
			}
			else
			{
				s_q=max_q-1;
			}
		}
	}

	debug3(max_q,min_q,s_q);
	return 0;
}
