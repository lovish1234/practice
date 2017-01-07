#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
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


#define VI vector< int >
#define ll long long int


int max(int x,int y)
{
    return  (x>y)?x:y;
}
int min(int x,int y)
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


bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}


const int N=200005;
int visited[N], color[N];
VI adj[N];
VI majColor(N,0);

void DFS(int u)
{
	visited[u]=1;
	majColor[color[u]]+=1;
	f(i,adj[u].size())
	{
		if(visited[adj[u][i]]==0)
		{
			DFS(adj[u][i]);
		}
	}
}

int main()
{
	int n,m,k,a,b;
	cin >> n >> m >> k;
	f(i,n)
	{
		cin >> color[i];
		visited[i]=0;
	}

	f(i,m)
	{
		cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	
	VI::iterator it;
	int sumColor=0,majorColor=0,ans=0;
	
	f(i,n)
	{
		if(visited[i]==0)
		{
			sumColor=0;
			majorColor=0;
			majColor.assign(majColor.size(),0);

			DFS(i);

			for(it=majColor.begin();it!=majColor.end();++it)
			{
				sumColor+=(*it);
				if((*it)>majorColor)
				{
					majorColor=(*it);
				}
			}
			ans+=(sumColor-majorColor);
		}
	}

	cout << ans << "\n";
	return 0;
}
