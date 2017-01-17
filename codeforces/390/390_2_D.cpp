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


bool comparator(pair < ll, pair< ll,ll > > const& a, pair < ll, pair< ll,ll > > const& b)
{
	return a.F < b.F;
}


typedef pair<ll,ll> P;

int main()
{
	ll n,k,temp1,temp2,temp3;
	cin >> n >> k;

	vector < pair < ll, pair < ll, ll > > > P1;
	map < ll, ll > P2; // cannot be used here 
	priority_queue< P, vector<P>, greater<P> > P3;

	f(i,n)
	{
		temp1=i+1;
		cin >> temp2 >> temp3;
		P1.pb(mp (temp2, mp(temp3,temp1)));
	}
	sort(P1.begin(),P1.end(),comparator);
	f(i,k)
	{
		temp3=P1[i].S.F;
		temp1=P1[i].S.S;
		P3.push(mp(temp3,temp1));
	}
	temp1=(P3.top()).F;
	ll left=P1[k-1].F,right=temp1,range=right-left+1,maxrange=0,maxleft,minright;
	if(range > maxrange)
	{
		maxrange=range;
		maxleft=left;
		minright=right;
	}

	fab(i,k,n-1)
	{
		P3.pop();
		P3.push(mp(P1[i].S.F,P1[i].S.S));
		temp1=P3.top().F;
		left=P1[i].F;
		right=temp1;
		range=right-left+1;
		if(range>maxrange)
		{
			maxrange=range;
			maxleft=left;
			minright=right;
		}
	}
	
	if(maxrange==0)
	{
		cout << 0 << "\n";
		f(i,k)
		{
			cout << i+1 << " ";
		}
	}
	else
	{
		cout << maxrange << "\n";
		vector<ll> ans;
		f(i,n)
		{
			if((P1[i].F<=maxleft) && (P1[i].S.F>=minright))
			{
				ans.pb(P1[i].S.S);
			}
		}
		sort(ans.begin(),ans.end());
		f(i,k)
		{
			cout << ans[i] << " ";
		}
	}

	return 0;
}
