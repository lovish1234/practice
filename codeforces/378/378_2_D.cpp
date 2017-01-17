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

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define ll long long int

/*
#define max(x,y) (x>y)?x:y
#define min(x,y) (x>y)?y:x
#define max3(x,y,z)  ((x>y)?x:y)? ((x>z)?x:z): ((y>z)?y:z)
#define min3(x,y,z)  ((x<y)?x:y)? ((x<z)?x:z): ((y<z)?y:z)
*/

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

int comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}

typedef pair<int,int> P;
map< P,P > M;

int main()
{
	int n,number=0,index1=0,index2=0;
	ll maxr=0;
	
	cin >> n;
	vector< vector < int > > V;
	vector < int > temp;
	int x;
	f(i,n)
	{
		f(i,3)
		{
			cin >> x;
			temp.push_back(x);
		}
		sort(temp.begin(),temp.end());
		V.push_back(temp);
		temp.clear();
	}


	f(i,V.size())
	{
		if(maxr<V[i][0])
		{
			number=1;
			index1=i;
			maxr=V[i][0];
		}
	}

	
	f(i,V.size())
	{
		if(M.find(mp(V[i][1],V[i][2]))==M.end())
		{
			M[mp(V[i][1],V[i][2])]=mp(V[i][0],i);
		}
		
		else
		{

			int comp = min(V[i][1],(V[i][0]+M[mp(V[i][1],V[i][2])].F));
			if(maxr<comp)
			{
				number=2;
				index1=i;
				index2=M[mp(V[i][1],V[i][2])].S;
				maxr=comp;
			}
			if(V[i][0]>M[mp(V[i][1],V[i][2])].F)
			{
				M[mp(V[i][1],V[i][2])]=mp(V[i][0],i);
			}
		}
	}

	cout << number << "\n";
	if(number==1)
	{
		cout << index1+1;
	}
	else
	{
		cout << index1+1 << " " << index2+1;
	}

	return 0;
}
