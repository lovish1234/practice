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


int main()
{
	int n,temp;
	cin >> n;

	VL pre_ind,suf_ind;
	VI a;
	ll sum=0, tot_sum=0;
	f(i,n)
	{
		cin >> temp;
		tot_sum+=temp;
	
		a.pb(temp);
	}
	if((tot_sum%3)!=0)
	{
		debug(0);
		return 0;
	}

	sum=a[0];
	fab(i,1,n-2)
	{
		if(sum==(tot_sum/3))
		{
			pre_ind.pb(i);
		}
		sum+=a[i];
	}
	sum=a[n-1];
	fabr(i,n-2,1)
	{
		if(sum==(tot_sum/3))
		{
			suf_ind.pb(i);
		}
		sum+=a[i];
	}
	reverse(suf_ind.begin(),suf_ind.end());

	int pre_size=pre_ind.size(),suf_size=suf_ind.size();
	int low,high,mid;
	ll ans=0;
	/*	
	f(i,pre_size)
	{
		cout << pre_ind[i] << " ";
	}
	cout << "\n";
	f(i,suf_size)
	{
		cout << suf_ind[i] << " ";
	}
	cout << "\n";
	*/
	if(pre_size==0 || suf_size==0)
	{
		debug(0);
		return 0;
	}

	f(i,pre_size)
	{
		sum=pre_ind[i];
		low=0,high=suf_size-1;	
	
		if(pre_ind[i]>suf_ind[suf_size-1])
		{
			continue;
		}
		
		// binary search
		while(low<=high)
		{
			mid=low+(high-low+1)/2;
			if(suf_ind[mid]==sum)
			{
				break;
			}
			else if(suf_ind[mid]>sum)
			{
				high=mid-1;
			}
			else if(suf_ind[mid]<sum)
			{
				low=mid+1;
			}
		}
		//debug2(pre_ind[i],mid);
		ans+=(suf_size-mid);
	}
	debug(ans);
	return 0;
}
