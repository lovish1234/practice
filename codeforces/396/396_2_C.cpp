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
template<typename T> T power(T u,T v, ll m=MOD)
{
	T ans=1;
	while(v>0)
	{
		if(v%2==1) 
			ans=(ans%m*u%m)%m;
		v/=2;
		u=(u%m*u%m)%m;
	}
	return ans%m;
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

const int N=1002;
int a[26];
ll number=0;
int long_substr=1,min_split=1000;
ll dp[N],min_dp[N];

int IsValidStr(string s)
{
	int s_size=s.size();
	if(s_size==1)
	{
		return 1;
	}
	f(i,s_size)
	{
		if(a[s[i]-'a']<s_size)
		{
			return 0;
		}
	}
	return 1;
}

void getSets(string s,int split)
{
	int s_size=s.size(),pre_size,suf_size;
	/*
	if(s_size==1)
	{
		number=(number+1)%MOD;
		//debug2(min_split,split);
		min_split=min2(min_split,split);
		return;
	}*/
	string pre,suf;
	fab(i,1,s_size-1)
	{
		pre=s.substr(0,i);
		suf=s.substr(i,s_size-i);

		if(IsValidStr(pre))
		{
			pre_size=pre.size();
			long_substr=max2(pre_size,long_substr);
			if(IsValidStr(suf))
			{
				suf_size=suf.size();
	
				number=(number + power(2,suf_size-1))%MOD;
				long_substr=max2(long_substr,suf_size);

				min_split=min2(min_split,split);
				continue;
			}
			getSets(suf,split+1);
		}
	}
}

int main()
{

	int n;
	cin >> n;

	string s,pre,suf;
	cin >> s;
	int s_size=s.size();

	f(i,26)
	{
		cin >> a[i];
	}
	f(i,N)
	{
		dp[i]=0;
		min_dp[i]=1001;
	}
	dp[0]=1;dp[1]=1;	
	min_dp[1]=1,min_dp[0]=0;

	if(n==1)
	{
		cout<< "1\n" << "1\n" << "1\n";
		return 0;
	}
	
	fab(i,2,n)
	{
		int m=1002;
		fabr(j,i,1)
		{
			//suf=s.substr(j-1,i-j+1);
			//debug3(m,a[s[j]-'a'],i-j+1);

			m=min2(m,a[s[j-1]-'a']);
			if(m>=(i-j+1))
			//if(IsValidStr(suf))
			{
				long_substr=max2(long_substr,i-j+1);
				dp[i]=((dp[i]%MOD) +(dp[j-1])%MOD)%MOD;
				min_dp[i]=min2(min_dp[i],min_dp[j-1]+1);
			}
			else
			{
				break;
			}
		}
	}
	debug(dp[n]);
	debug(long_substr);
	debug(min_dp[n]);
/*
	if(IsValidStr(s))
	{
		number=power(2,s_size-1);
		long_substr=s_size;
		min_split=0;
	}
	else
	{
		getSets(s,1);
	}
*/
	return 0;
}
