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
	string a,b;
	cin >> a >> b;

	int a_sz=a.size(),b_sz=b.size();
	int array[a_sz+1][b_sz+1];
	
	f(i,a_sz+1)
	{
		f(j,b_sz+1)
		{
			if(i==0||j==0)
			{
				array[i][j]=0;
			}
			else
			{
				if(a[i-1]==b[j-1])
				{
					array[i][j]=max3(array[i-1][j],array[i][j-1],array[i-1][j-1]+1);
				}
				else
				{
					array[i][j]=max2(array[i-1][j],array[i][j-1]);
				}
			}
		}
	}
/*
	f(i,b_sz+1)
	{
		cout << i << " ";
	}
	cout << "\n";
	f(i,a_sz+1)
	{
		cout << i << " ";
		f(j,b_sz+1)
		{
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
	cout << array[a_sz][b_sz];
*/
	int itr1=a_sz+1, itr2=b_sz+1;
	string ans("");
	while(itr1!=0 && itr2!=0)
	{
		if(a[itr1-1]==b[itr2-1])
		{
			ans+=a[itr1-1];
			itr1--,itr2--;
		}
		else if(array[itr1-1][itr2] > array[itr1][itr2-1])
		{
			itr1--;
		}
		else
		{
			itr2--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout << ans;
	return 0;
}
