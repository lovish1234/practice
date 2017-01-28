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
#include<bitset>


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

#define EPS 0.0000001


#define ll long long int

typedef pair<int , int> PI;
typedef vector< int > VI;
typedef vector < vector < int > > VVI;


typedef pair<ll , ll> PL;
typedef vector< int > VL;
typedef vector < vector < ll > > VVL;

int main()
{
	ll n,k,a,b,minum,manum;
	char mi,ma;
	cin >> n >> k >> a >> b;
	if(a>b)
	{
		mi='B';ma='G';
		minum=b;manum=a;
	}
	else
	{
		mi='G';ma='B';
		minum=a;manum=b;
	}

	// if not possible to fill 
	if(((minum+1)*k)<manum)
	{
		cout << "NO";
		return 0;
	}

	int pockets[minum+1];
	f(i,minum+1)
	{
		pockets[i]=0;
	}

	int manum_or=manum;
	while(manum>0)
	{
		f(i,minum+1)
		{
			if(manum==0)
			{	
				break;
			}
			manum--;
			pockets[i]++;
		}
	}

	f(i,minum)
	{
		
		f(j,pockets[i])
		{
			cout << ma;
		}
		cout << mi;
	}
	
	f(j,pockets[minum])
	{
		cout << ma;
	}
	
	return 0;
}
