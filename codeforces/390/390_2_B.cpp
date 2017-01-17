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


int main()
{
	int a[4][4];
	char c;
	f(i,4)
	{
		f(j,4)
		{
			cin >> c;
			if(c=='x')
			{
				a[i][j]=1;
			}
			else if(c=='o')
			{
				a[i][j]=-1;
			}
			else
			{
				a[i][j]=0;
			}
		}
	}

	f(i,4)
	{
		f(j,2)
		{
			if(a[i][j] + a[i][j+1] + a[i][j+2] ==2)
			{
				cout << "YES";
				return 0;
			}
		}
	}


	f(j,4)
	{
		f(i,2)
		{
			if(a[i][j] + a[i+1][j] + a[i+2][j] ==2)
			{
				cout << "YES";
				return 0;
			}
		}
	}

	if(a[2][0] + a[1][1] + a[0][2] == 2)
	{
		cout << "YES";
		return 0;
	}

	if(a[3][1] + a[2][2] + a[1][3] == 2)
	{
		cout << "YES";
		return 0;
	}

	if(a[0][1] + a[1][2] + a[2][3] == 2)
	{
		cout << "YES";
		return 0;
	}

	if(a[1][0] + a[2][1] + a[3][2] == 2)
	{
		cout << "YES";
		return 0;
	}

	if(a[3][0] + a[2][1] + a[1][2] == 2)
	{
		cout << "YES";
		return 0;
	}

	if(a[0][3] + a[2][1] + a[1][2] == 2)
	{
		cout << "YES";
		return 0;
	}

	if(a[0][0] + a[1][1] + a[2][2] == 2)
	{
		cout << "YES";
		return 0;
	}

	if(a[3][3] + a[1][1] + a[2][2] == 2)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}
