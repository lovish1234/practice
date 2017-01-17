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
	int n;
	cin >> n;
	int atNorth=1, atSouth=0,disp=0;
	int disArray[n], dirArray[n];
	string input;
	f(i,n)
	{
		cin >> disArray[i] >> input;
		if(input=="North")
		{
			dirArray[i]=1;
		}
		else if(input=="South")
		{
			dirArray[i]=2;
		}
		else if(input=="East")
		{
			dirArray[i]=3;
		}
		else if(input=="West")
		{
			dirArray[i]=4;
		}
	}

	f(i,n)
	{
		
		if(atNorth==1 && dirArray[i]!=2)
		{
			cout << "NO";
			return 0;
		}
		if(atSouth==1 && dirArray[i]!=1)
		{
			cout << "NO";
			return 0;
		}
	
		if(dirArray[i]==1)
		{
			disp-=(disArray[i]);
			if(disp<0)
			{
				cout << "NO" << "\n";
				return 0;
			}
		}
		else if(dirArray[i]==2)
		{
			disp+=(disArray[i]);
			//cout << disArray[i] << " " << disp << "\n";
			if(disp>20000)
			{
				cout << "NO" << "\n";
				return 0;
			}
		}

		if(disp==20000)
		{
			atSouth=1;
			atNorth=0;
		}
		else if(disp==0)
		{
			atNorth=1;
			atSouth=0;
		}
		else
		{
			atSouth=0;
			atNorth=0;
		}

	}

	if(atNorth==1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}
