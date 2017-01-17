#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

#include<string>
#include<list>
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

#define ll long long int

bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}
const int N=1005;
int n,m,k,temp,u,v;
int cnt=0,sum=0;
int visited[N];
vector< int > adj[N]; // adjecency list

void dfs(int u)
{
	if(visited[u]==1)
	{
		return;
	}
	else
	{
		// cnt the number of edges between connected component
		cnt++;
		visited[u]=1;
		f(i,adj[u].size())
		{
			if(visited[adj[u][i]]==0)
			{
				dfs(adj[u][i]);
			}
		}
	}
}

int main()
{

	cin >> n >> m >> k;
	int govt[k];
	f(i,k)
	{
		cin >> temp;
		govt[i]=temp-1;
	}

	//adjecency list
	f(i,m)
	{
		cin >> u >> v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}

	// not isited any vertex yet
	f(i,n)
	{
		visited[i]=0;
	}

	// get number of vertices in every component
	vector<int> componentSum(k);
	f(i,k)
	{
		cnt=0;
		dfs(govt[i]);
		componentSum[i]=cnt;

		// sum of vertices in all <<strongly>> connected cliques 
		sum+=cnt;
	}

	sort(componentSum.begin(),componentSum.end());
	reverse(componentSum.begin(),componentSum.end());

	// add the number of vertices not visited to the largest component
	componentSum[0]+=(n-sum);

	int ans=0;
	f(i,k)
	{
		ans+=((componentSum[i]*(componentSum[i]-1))/2);
	}

//	cout << "Here" << "\n";
	cout << (ans-m) << "\n";
	return 0;
}
