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

vector<int> findZeroIndex(ll n, ll k)
{
	vector<int> ans;
	int i=0;
	while(n)
	{
		if(n%10==0)
		{
			ans.pb(i);
		}
		n/=10;
		i++;
	}
	return ans;
}

int findNoDigits(ll n)
{
	int ans=0;
	while(n)
	{
		n/=10;
		ans++;
	}
	return ans;

}
int main()
{
	ll n,k,noDigits,zeroIndex_size;
	cin >> n >> k;
	vector<int> zeroIndex;
	zeroIndex=findZeroIndex(n,k);
	zeroIndex_size=zeroIndex.size();
	noDigits=findNoDigits(n);
	/*
	f(i,zeroIndex.size())
	{
		cout << zeroIndex[i];
	}
	cout << findNoDigits(n);
	*/

	if(zeroIndex_size==0)
	{
		cout << noDigits;
		return 0;
	}
	else if(zeroIndex_size<k)
	{
		cout << noDigits-1;
		return 0;
	}
	//cout << zeroIndex[k-1];
	cout << zeroIndex[k-1]-(k-1);	

	return 0;
}
