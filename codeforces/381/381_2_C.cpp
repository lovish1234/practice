#include<cstdio>
#include<iostream>
#include<cmath>

#include<string>
#include<list>
#include<queue>
#include<unordered_map>

using namespace std;

#define sd(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define f(i,n) for(int i=0;i<n;i++)
#define fl(i,a,b) for(int i=a;i<=b;i++)

#define  mz(array)  memset(array,0,sizeof(array))

#define mp make_pair

#define ll long long int

int main()
{
	ll n,m,minlen=INT_MAX,l,r,ans;
	cin >> n >> m;
	f(i,m)
	{
		cin >> l >> r;
		if((r-l+1)<minlen)
		{
			minlen=(r-l)+1;
		}
	}
    cout << minlen << "\n";
	f(i,n)
	{
		ans = i%minlen;
		cout << ans << " "; 
	}
	cout << "\n";
	return 0;
}
