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
#include<set>

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


bool comparator(pair< int,vector<int> > const& a, pair< int,vector<int> > const& b)
{
	return a.F < b.F;
}

const int N=3000;
int redFlag=0;
int n,m;
// adjecency list
vector< int > P[N];

// for DFS
vector< int > visited(N,0);

// to store the component of map with '.'
vector< pair < int, vector<  int > > > component;
vector< int > temp_component;

// to store lakes which are oceans
set<int> O;

void DFS(int s)
{
	if(O.find(s)!=O.end())
	{
		redFlag=1;
		return;
	}

	if(visited[s]==1)
	{
		return;
	}
	else
	{
		visited[s]=1;
		temp_component.pb(s);
		f(i,P[s].size())
		{
			DFS(P[s][i]);
		}
	}
}


int main()
{
	int k;
	char temp;
	cin >> n >> m >> k;

	int lake[n*m];
	f(i,n*m)
	{
		cin >> temp;
		lake[i]=temp=='*'?0:1;
	}

	int location,left,right,up,down;

	f(i,n*m)
	{
		P[i].clear();
	}
	fab(i,1,n-1)
	{
		fab(j,1,m-1)
		{
			location=i*m+j;
			if(lake[location]==1)
			{
				left=lake[location-1];
				right=lake[location+1];
				up=lake[location-m];
				down=lake[location+m];
				if(left==1)
				{
					P[location-1].pb(location);
					P[location].pb(location-1);
				}
				if(right==1)
				{
					P[location+1].pb(location);
					P[location].pb(location+1);
				}
				if(up==1)
				{
					P[location-m].pb(location);
					P[location].pb(location-m);
				}
				if(down==1)
				{
					P[location+m].pb(location);
					P[location].pb(location+m);
				}
			}
		}
	}
	
	// lakes which are actully oceans 
	fab(i,0,n)
	{
		fab(j,0,m)
		{
			location=i*m+j;
			if(i==0 || i==(n-1) || j==0 || j==(m-1))
			{
				O.insert(location);
			}
		}
	}

/*	
	f(i,n*m)
	{
		debug(i);
		f(j,P[i].size())
		{
			cout << P[i][j] << " ";
		}
		cout << "\n";
	}
*/

	component.clear();
	f(i,n*m)
	{
		if(lake[i]==1 && visited[i]==0)
		{
			temp_component.clear();
			DFS(i);
			if(redFlag==1)
			{
				redFlag=0;
				continue;
			}
			component.pb(mp(temp_component.size(),temp_component));
		}
	}
	sort(component.begin(),component.end(),comparator);		
/*
	f(i,component.size())
	{
		cout << component[i].F << "\n";
		f(j,component[i].S.size())
		{
			cout <<(component[i].S[j]) << " ";
		}
		cout << "\n";
	}
	*/
	int numOfLakes=component.size(),minFill=0;
	f(i,numOfLakes-k)
	{
		minFill+=component[i].F;
		f(j,component[i].S.size())
		{
			lake[component[i].S[j]]=0;
		}
	}
	cout << minFill << "\n";;

	char finalLake[n][m];
	int row,column;
	f(k,n*m)
	{
		row=k/m;
		column=k%m;
		finalLake[row][column]=(lake[k]==0)?'*':'.';
	}

	f(i,n)
	{
		f(j,m)
		{
			cout << finalLake[i][j];
		}
		cout << "\n";
	}

	return 0;
}
