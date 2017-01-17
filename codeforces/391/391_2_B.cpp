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
#include<map>
#include<set>
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
typedef pair<ll,ll> P;



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


bool comparator(pair < ll, pair< ll,ll > > const& a, pair < ll, pair< ll,ll > > const& b)
{
	return a.F < b.F;
}


int gcd(int x, int y)
{
	while(x%=y)
	{
		int u=x;
		x=y;
		y=u;
	}
	return y;
}

int IsPrime(int n)
{
	fab(i,2,sqrt(n))
	{
		if(!(n%i))
		{
			return 0;
		}
	}
	return 1;
}

const int MAX=100005;
bool v[MAX];
int  sp[MAX];

void smallestPrime()
{
	f(i,MAX)
	{
		v[i]=0;
	}
	for(int i=2;i<MAX;i+=2)
	{
		sp[i]=2;
		v[i]=1;
	}
	ll product;
	for(int i=3;i<MAX;i+=2)
	{
		//debug(i);
		if(!v[i])
		{
			sp[i]=i;
			v[i]=1;
			for(ll j=i;(j*i)<MAX;j+=2)
			{
				product=i*j;
				//debug3(i,j,product);
				if(!v[product])
				{
					v[product]=1;
					sp[product]=i;
				}
			}
		}
	}

}

int main()
{
	smallestPrime();

	int n;
	cin >> n;
	vector<int> p(n,0);
	map <int,int> M;
	f(i,n)
	{
		cin >> p[i];
	}
	if(n==1)
	{
		cout << "1";
		return 0;
	}

	f(i,n)
	{
		if(M.find(sp[p[i]])!=M.end() && p[i]!=1)
		{
			M[sp[p[i]]]++;
		}
		else
		{
			M[sp[p[i]]]=1;
		}
	}

	map<int,int>::iterator it;
	int max=1;
	for(it=M.begin();it!=M.end();++it)
	{
		cout << it->first << " " << it->second << "\n";
		if(max<it->second)
		{
			max=it->second;
		}
	}

	cout << max;
	return 0;
}
