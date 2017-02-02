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
	return 0;
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
bool comparator1(pair<PI,PI> const& a, pair<PI,PI> const& b)
{
	return a.F.S < b.F.S;
}
bool comparator2(pair<PI,PI> const& a, pair<PI,PI> const& b)
{
	return a.S.S < b.S.S;
}



int main()
{
	int n,l,r;
	cin >> n >> l >> r;
	
	int a[n],cc[n],b[n];
	f(i,n)
	{
		cin >> a[i];
	}
	f(i,n)
	{
		cin >> cc[i];
		b[i]=0;
	}
/*
	if(r-l+1<n)
	{
		cout << "-1";
		return 0;
	}
*/

	vector<pair<PI,PI> > p;
	f(i,n)
	{
		p.pb(mp(mp(a[i],cc[i]),mp(b[i],i+1)));
	}
	sort(p.begin(),p.end(),comparator1);

	/*	f(i,n)
	{
		cout << p[i].F.F << p[i].F.S;
		cout << p[i].S.F << p[i].S.S;
		cout << "\n";
	}*/

	p[0].S.F=l;
	fab(i,1,n-1)
	{
		p[i].S.F=p[i-1].S.F-p[i-1].F.F+1+p[i].F.F;
		if(p[i].S.F<l)
		{
			p[i].S.F=l;
		}
		else if(p[i].S.F>r)
		{
			cout << "-1";
			return 0;
		}
	}

	sort(p.begin(),p.end(),comparator2);	
	f(i,n)
	{
		cout << p[i].S.F << " " ;
	}
	
	return 0;
}
