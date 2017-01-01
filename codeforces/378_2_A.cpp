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

#define max(x,y) (x>y)?x:y
#define min(x,y) (x>y)?y:x

bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	if(len==0)
	{
		cout << 1;
		return 0;
	}

	int pV=-1, cV,maxDist=0;
	f(i,len)
	{
		if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y')
		{
			maxDist=max(i-pV,maxDist);
			pV=i;
		}
	}
	//cout << s.length()-pV << maxDist;
	maxDist=max((s.length()-pV),maxDist);
	cout << maxDist;
	return 0;
}
