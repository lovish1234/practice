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
#define MOD 100000000000000007

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
			ans=(ans*u)%MOD;
		v/=2;
		u=(u*u)%MOD;
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


int int_mod( int a, int b)
{
	return (a%b+b)%b;
}

int main()
{
	string s,b,t;
	cin >> s;
	cin >> b;
	bool bad[27];
	f(i,27)
	{
		bad[i+1]=b[i]-'0';
	}

	int k;
	cin >> k;
	
	int l=s.size(),bcnt=0;
	ll hv,front;
	int chartoi,chartoj,base=27;
	set<ll> M;


	
	f(i,l)
	{
		bcnt=0;
		//chartoi=s[i]-'0'-48;
		hv=0;
		fab(j,i,l-1)
		{
			chartoj=s[j]-'0'-48;
			front= ((((power(base,j-i))%MOD) * ((hv)%MOD) )%MOD); 
			hv=((front%MOD) + (chartoj%MOD))%MOD;
			//debug3(i,j,hv);

			//cout << chartoj << bad[chartoj] << endl;
			if(!bad[chartoj])
			{
				bcnt++;
			}
			if(bcnt>k)
			{
				break;
			}
			//debug3(i,j,t);		
			// if hash of substring not in set add it to unqiue substr
			if(M.find(hv)==M.end())
			{
				M.insert(hv);
			}
		}
	}

	cout << M.size() << "\n";
	return 0;
}
