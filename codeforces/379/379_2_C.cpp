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
#define fl(i,a,b) for(int i=a;i<=b;i++)

#define  mz(array)  memset(array,0,sizeof(array))

#define mp make_pair
#define F first
#define S second

#define ll long long int

const int N=2000000;
ll n,s1,s2;
ll x,s;
vector< pair<ll,ll> > s1hc(N),s2hc(N);

bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}

int binarySearch(int cost )
{
	int low = 0, high = s2, mid;
	while(low < high)
	{
		mid = low + ((high-low)/2);
		if(cost >= s2hc[mid].S)
		{
			low = mid;
		}
		else
		{
			high = mid-1;
		}
		cout << low << " " << high << "\n";
		break;
	}
	return s2hc[mid].F;
}

int main()
{
	cin >> n >> s1 >> s2;
    cin >> x >> s;
	f(i,s1)
	{
		cin >> s1hc[i].F;
	}
 	f(i,s1)
	{
		cin >> s1hc[i].S;
	}
    f(i,s2)
	{
		cin >> s2hc[i].F;
	}
	f(i,s2)
	{
		cin >> s2hc[i].S;
	}
	//sort(s1hc.begin(),s1hc.end(),comparator);
	int c_new,x_new,n_new,ans = 1LL*n*x;
	f(i,s1)
	{
		c_new=s-s1hc[i].S;
		x_new=s1hc[i].F;
		if(c_new<0) continue;

		n_new=n-binarySearch(c_new);
		cout << n_new << " " << x_new << "\n";
		ans = (ans> 1LL*n_new*x_new)?ans:1LL*n_new*x_new;
	}
	cout << ans;
	return 0;
}
