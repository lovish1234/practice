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
	ll n,m,temp,maxmin=0,extra=0,changes=0;
	cin >> n >> m;

	maxmin=(n/m);
	extra=(n%m);
	
	ll array[n];
	map<ll,ll> M,N;
	map<ll,ll>::iterator it;
	f(i,n)
	{
		cin >> temp;
		array[i]=temp;
		if(M.find(temp)!=M.end())
		{
			M[temp]++;
		}
		else
		{
			M.insert(mp(temp,1));
		}
	}
	f(i,m)
	{
		if(M.find(i+1)==M.end())
		{
			M.insert(mp(i+1,0));
		}
	}


	int flag=0;
	it=M.begin();
	f(i,n)
	{
		if(flag==1)
		{
			break;
		}

		if(array[i]>m && M[array[i]]>0 && (it->first)<=m)
		{
			while(it!=M.end() && (it->second)>=maxmin)
			{
				++it;
			}
			if(it!=M.end() && it->first<=m)
			{
				//debug2(array[i],it->first);
				
				M[it->first]++;
				M[array[i]]--;
				if(M[array[i]]==0)
				{
					M.erase(array[i]);
				}
				changes++;
				array[i]=it->first;
			}
			else
			{
				break;
				flag=1;
			}
		}		
	}

	flag=0;
	it=M.begin();
	f(i,n)
	{
		if(flag==1)
		{
			break;
		}
		if(M[array[i]]>(maxmin) && array[i]<=m)
		{
			while(it!=M.end() && (it->second)>=maxmin)
			{
				++it;
			}

			if(it!=M.end())
			{
				(it->second)++;
				M[array[i]]--;
				changes++;
				array[i]=it->first;
			}
			else
			{
				flag=1;
				break;
			}
		}
	}

	cout << maxmin << " " << changes << "\n";
	f(i,n)
	{
		cout << array[i] << " ";
	}
	
	return 0;
}
