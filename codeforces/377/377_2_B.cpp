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

bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}

int main()
{
	int n,k,temp=0,sum=0;
	cin >> n >> k;

	vector<int> S;
	S.pb(k);
	f(i,n)
	{
		cin >> temp;
		S.pb(temp);
	}
	S.pb(k);


	f(i,S.size()-1)
	{
//		cout << S[i] << " ";
		temp=k-S[i]-S[i+1];
		if(temp>0)
		{
			sum+=temp;
			S[i+1]+=temp;
		}
	}
//	cout << "\n";
	cout << sum << "\n";

	fab(i,1,n)
	{
		cout << S[i] << " ";
	}	
	return 0;
}
