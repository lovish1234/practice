#include<cstdio>
#include<cmath>
#include<algorithm>
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

int block_size;
bool comparator( pair<PI,int> const& a, pair<PI,int> const& b)
{
	int a_sq=(a.F.F/block_size);
	int b_sq=(b.F.F/block_size);

	if(a_sq==b_sq)
	{
		return a.F.S < b.F.S;
	}
	else
	{
		return a_sq<b_sq;
	}
}

const int N=1000005;
const int N1=200005;
ll currentans=0;
int a[N1];
int mo_left=0, mo_right=-1;
int cnt[N];

void moveLL(int x)
{
	while(x>0)
	{
		cnt[a[mo_left-1]]++;
		currentans+=( (2*cnt[a[mo_left-1]]-1)*(a[mo_left-1]));	
		mo_left--;
		x--;
	}
}

void moveLR(int x)
{
	while(x>0)
	{
		currentans-=( (2*cnt[a[mo_left]]-1)*a[mo_left]);
		cnt[a[mo_left]]--;

		mo_left++;
		x--;
	}
}

void moveRL(int x)
{
	while(x>0)
	{
		currentans-=( (2*cnt[a[mo_right]]-1)*a[mo_right]);
		cnt[a[mo_right]]--;
	
		mo_right--;
		x--;
	}
}

void moveRR(int x)
{
	while(x>0)
	{
		cnt[a[mo_right+1]]++;
		currentans+=((2*cnt[a[mo_right+1]]-1)*a[mo_right+1]);	
	
		mo_right++;
		x--;
	}
}


int main()
{
	// number of integers and number of queries
	int n,m;
	vector< pair<PI,int> > q;
	
	sd2(n,m);
	block_size=(n/sqrt(n));

//	int a[n];
	f(i,n)
	{
		sd(a[i]);
	}

//	vector<PI> q;
	int temp1,temp2;
	f(i,m)
	{
		sd2(temp1,temp2);
		q.pb(mp(mp(temp1-1,temp2-1),i));
	}
	sort(q.begin(),q.end(),comparator);

//	int mo_left=0,mo_right=-1;

	// should be global variables
	ll ans[m];
	f(i,N)
	{
		cnt[i]=0;
	}
	f(i,m)
	{

		if(q[i].F.S!=mo_right)
		{
			if(q[i].F.S>mo_right)
			{
				moveRR(q[i].F.S-mo_right);
			}
			else
			{
				moveRL(mo_right-q[i].F.S);
			}
		}
		
		if(q[i].F.F!=mo_left)
		{
			if(q[i].F.F>mo_left)
			{
				moveLR(q[i].F.F-mo_left);
			}
			else
			{
				moveLL(mo_left-q[i].F.F);
			}
		}
		ans[q[i].S]=currentans;
	}
	f(i,m)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}
