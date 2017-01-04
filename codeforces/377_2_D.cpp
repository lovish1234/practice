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
	int n,m,temp,prep=0;
	cin >> n >> m;
	vector<int> A;
	f(i,n)
	{
		cin >> temp;
		A.pb(temp);
	}

	f(i,m)
	{
		cin >> temp;
		prep+=temp;
	}
	
	//day alloted to prepration of and exam of which subject
	map <int, int> H;
	f(i,n)
	{
		if(H.find(A[i])==H.end() && A[i]!=0)
		{
			H[A[i]]=i;
		}
	}
	map<int,int>::iterator it;
	int all=INT_MIN;
	for(it=H.begin();it!=H.end();++it)
	{
		if(it->second>all)
		{
			all=it->second;;
		}
	}

	// No exam for given subject
	f(i,m)
	{
		if(H.find(i+1)==H.end())
		{
			cout << "-1" << "\n";
			return 0;
		}
	}

	// Not enough days for prepration 
	int l=0,r=n-1,mid=l+(r-l)/2;
	if((r+1-prep-m)<0 || r<all)
	{
		cout << -1 << "\n";
		return 0;
	}

	while(l<=r)
	{
		mid= l+(r-l)/2;

		// have sufficient for prepration and taking exams
		if((mid+1-prep-m)==0 && mid>=all)
		{
			break;
		}
		// either not sufficient days or all exams have not taken place
		else if(( mid<all) || ((mid+1-prep-m)<0))
		{
			l=mid+1;
		}
		// more than sufficient days for preprations of exams
		else if((mid+1-prep-m)>0 || mid>=all)
		{
			r=mid-1;
		}
	}

	
	fab(i,mid,n)
	{
		if(A[i]!=0)
		{
			cout << i+1 << "\n";
			return 0;
		}
	}
	cout << "-1" << "\n";
	return 0;
}
