#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

#include<string>
#include<list>
#include<queue>
#include<unordered_map>
#include<unordered_set>


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

int main()
{
	int h,w;
	cin >> h >> w;

	char array[h][w];
	f(i,h)
	{
		f(j,w)
		{
			cin >> array[i][j];
		}
	}

	int vertical[h-1][w];
	int horizontal[h][w-1];

	f(j,w)
	{
		f(i,h-1)
		{
			if(array[i][j]=='.' && array[i+1][j]=='.')
			{
				vertical[i][j]=1;
			}
			else
			{
				vertical[i][j]=0;
			}
		}
	}

	f(i,h)
	{
		f(j,w-1)
		{
			if(array[i][j]=='.' && array[i][j+1]=='.')
			{
				horizontal[i][j]=1;
			}
			else
			{
				horizontal[i][j]=0;
			}
		}
	}
    

	int q,sum1,sum2,sum;
	cin >> q;
	int l1[q],l2[q],r1[q],r2[q];

	f(i,q)
	{
		sd2(l1[i],r1[i]);
		sd2(l2[i],r2[i]);
	}
	for(int k=0;k<q;k++)
	{
		sum1=0,sum2=0,sum=0;
        for(int i=(l1[k]-1);i<=(l2[k]-1);i++)
		{
			for(int j=(r1[k]-1);j<=(r2[k]-2);j++)
			{
				sum1+=horizontal[i][j];
			}
		}
		for(int i=(l1[k]-1);i<=(l2[k]-2);i++)
		{
			for(int j=(r1[k]-1);j<=(r2[k]-1);j++)
			{
				sum2+=vertical[i][j];
			}
		}
	    sum = sum1+sum2;
		cout << sum << "\n";
		//cout << k << "\n";
	}
	return 0;
}
