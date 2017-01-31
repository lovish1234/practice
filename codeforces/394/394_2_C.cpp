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

#define  mz(X)  memset(array,0,sizeof(array))

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

int ans=2500,n;
int X[51][3];
void getSets(int s1, int s2, int s3, int cost)
{

	// first 3 DFS + then greedy
	if(s1==-1)
	{
		f(i,n)
		{
			s1=i;
			getSets(s1,s2,s3,cost+X[i][0]);
		}
	}
	else if(s2==-1)
	{
		f(i,n)
		{
			s2=i;
			if(s2!=s1)
			{
				getSets(s1,s2,s3,cost+X[i][1]);
			}
		}
	}
	else if(s3==-1)
	{
		f(i,n)
		{
			s3=i;
			if(s3!=s1 && s3!=s2)
			{
				getSets(s1,s2,s3,cost+X[i][2]);
			}
		}
	}
	else
	{
		f(i,n)
		{
			if(i!=s1 && i!=s2 && i!=s3)
			{
				cost+=min3(X[i][0],X[i][1],X[i][2]);
			}
		}
		if(cost<ans)
		{
			ans=cost;
		}
	}
	
}

int main()
{
	int m,temp,dist;
	string s;
	cin >> n >> m;
	temp=n;

	f(i,n)
	{
		f(j,3)
		{
			X[i][j]=100;
		}
	}

	f(j,n)
	{
		cin >> s;
		f(i,m)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				dist=min2(abs(i-0),abs(m-i));
				if(dist<X[j][0])
				{
					X[j][0]=dist;
				}
			}

			if(s[i]>='a' && s[i]<='z')
			{
				dist=min2(abs(i-0),abs(m-i));
				if(dist<X[j][1])
				{
					X[j][1]=dist;
				}
			}
			
			if(s[i]=='#' || s[i]=='*' || s[i]=='&')
			{
				dist=min2(abs(i-0),abs(m-i));
				if(dist<X[j][2])
				{
					X[j][2]=dist;
				}
			}
		}
	}
	getSets(-1,-1,-1,0);	
	cout << ans;
	return 0;
}
