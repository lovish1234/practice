#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#include<string>
#include<list>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;

#define sd(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define fr(n,i) for(int i=(n-1);i>=0;i--)
#define frab(i,b,a) for(int i=b;i>=a;i--)

#define debug(a) cout<< a << "\n"
#define debug2(a,b) cout << a << " " < b << "\n"
#define debug3(a,b,c) cout << a << " " << b << " " << c << "\n"

#define  mz(array)  memset(array,0,sizeof(array))

#define mp make_pair
#define F first
#define S second

#define ll long long int

bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}

const int N=35;
int t[N];
int n;
// to mark the coordinates where an explosion would occur
set < pair <int,int > > E;

// for memoization
bool memory[301][301][31][3][3];
// to get new direction for firework after t_i steps
pair< pair<int,int>, pair<int,int> >  getNewDir(pair <int,int> oldDir)
{
	if (oldDir.F==1 && oldDir.S==1) return mp(mp(1,0),mp(0,1));
	if (oldDir.F==0 && oldDir.S==1) return mp(mp(-1,1),mp(1,1));
	if (oldDir.F==-1 && oldDir.S==1) return mp(mp(-1,0),mp(0,1));
	if (oldDir.F==-1 && oldDir.S==0) return mp(mp(-1,1),mp(-1,-1));
	if (oldDir.F==-1 && oldDir.S==-1) return mp(mp(-1,0),mp(0,-1));
	if (oldDir.F==0 && oldDir.S==-1) return mp(mp(-1,-1),mp(1,-1));
	if (oldDir.F==1 && oldDir.S==-1) return mp(mp(1,0),mp(0,-1));
	if (oldDir.F==1 && oldDir.S==0) return mp(mp(1,1),mp(1,-1));
}

void DFS(int branch, int x, int y, pair< pair<int,int>, pair<int,int> > newDir)
{

	if(branch>n)
	{
		return;
	}	

	pair < pair <int,int >,  pair<int,int> > newFDir, newSDir;
	pair <int,int> fDir (newDir.F);
	pair <int,int> sDir (newDir.S);
	int newX,newY;

	memory[x+150][y+150][branch-1][fDir.F+1][fDir.S+1]=1;
	memory[x+150][y+150][branch-1][sDir.F+1][sDir.S+1]=1;
	fab(i,1,t[branch-1])
	{
		newX=(x+(fDir.F*i));
		newY=(y+(fDir.S*i));
		E.insert(mp(newX,newY));
		//memory[newX+150][newY+150][branch-1][fDir.F+1][fDir.S+1]=1;
	}
	fab(i,1,t[branch-1])
	{
		newX=(x+(sDir.F*i));
		newY=(y+(sDir.S*i));
		E.insert(mp(newX,newY));
		//memory[newX+150][newY+150][branch-1][sDir.F+1][sDir.S+1]=1;
	}

	newFDir = getNewDir(fDir);
	newSDir = getNewDir(sDir);
	newX=x+(fDir.F*t[branch-1]),newY=y+(fDir.S*t[branch-1]);
	if(memory[newX+150][newY+150][branch][newFDir.F.F+1][newFDir.F.S+1]==0)
	{
		DFS(branch+1,newX,newY,newFDir);	
	}

	newX=x+(sDir.F*t[branch-1]),newY=y+(sDir.S*t[branch-1]);
	if(memory[newX+150][newY+150][branch][newSDir.S.F+1][newSDir.S.S+1]==0)
	{
		DFS(branch+1,newX,newY,newSDir);
	}
}

int main()
{
	pair <int,int> oldDir(0,1);
	pair < pair <int,int>, pair<int,int> > newDir;
	newDir=getNewDir(oldDir);
	memset(memory,0,sizeof(memory));

	cin >> n;
	f(i,n)
	{
		cin >> t[i];
	}

	memory[150][150][0][1][2]=1;
	f(i,t[0])
	{
		//memory[150][150+i][0][0+1][1+1]=1;
		E.insert(mp(0,i));
	}
	
	DFS(2,0,t[0]-1, newDir);
	cout << E.size();
	return 0;
}
