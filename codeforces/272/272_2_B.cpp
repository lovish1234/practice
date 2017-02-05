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
} //using this instead of inbuilt pow due to precision issues in that



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

int foo(int n,int r)
{
     if(n==r || r==0) return 1;
     if(r==1) return n;
     return foo(n-1,r) + foo(n-1,r-1);
}

int main()
{
	string s,t;
	cin >> s >> t;
	int x=0,y=0,cnt=0,s_size=s.size();
	f(i,s_size)
	{
		if(s[i]=='+')
		{
			x++;
		}
		else if(s[i]=='-')
		{
			x--;
		}
	}
	double ans=1;
	f(i,s_size)
	{
		if(t[i]=='+')
		{
			y++;
		}
		else if(t[i]=='-')
		{
			y--;
		}
		else
		{
			cnt++;
		}
	}
	if(cnt==0 && x==y)
	{
		ans=1;
		cout.precision(15);
		cout << fixed << ans;
		return 0;
	}
	if((cnt<abs(x-y)) || (cnt%2==0 && (abs(x-y)%2)==1) || (cnt%2==1 && (abs(x-y)%2)==0))
	{
		ans=0;
		cout.precision(15);
		cout << fixed << ans;
		return 0;
	}
	
	int no_heads = (cnt - abs(x-y))/2;
	ans=pow(0.5,cnt)*foo(cnt,no_heads);
	cout.precision(15);
	cout << fixed << ans;

	return 0;
}
