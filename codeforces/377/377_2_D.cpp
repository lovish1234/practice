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

int n,m,temp=0,prep=0;
vector<int> A,B;

int checkAll(vector<int> A, int index)
{
	unordered_map<int,int> M;
	fr(index+1,i)
	{
		if(M.find(A[i])==M.end() && A[i]!=0)
		{
			M[A[i]]=i;
		}
	}
	//cout << "checkall" << "\n";
	//debug2(M.size(),m);
	if(M.size()==m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkOrder(vector<int> A,int index)
{
	unordered_map<int,int> M;
	map<int,int> M_X;
	fr(index+1,i)
	{
		if(M.find(A[i])==M.end() && A[i]!=0)
		{
			M[A[i]]=i;
			M_X[i]=A[i];
		}
	}

	map<int,int>::iterator it;
	//unordered_map<int,int>::reverse_iterator rit;
	int count=0,given=0;
	for(it=M_X.begin();it!=M_X.end();++it)
	{
		//debug2(it->second,it->first);
		if((B[(it->second)-1]+count+given)>(it->first))
		{
			return 0;
		}
		given+=B[(it->second)-1];
		count++;
	}
	return 1;

}



int main()
{
	cin >> n >> m;
	f(i,n)
	{
		cin >> temp;
		A.pb(temp);
	}

	f(i,m)
	{
		cin >> temp;
		B.pb(temp);
		prep+=temp;
	}

	int l=0,r=n-1,mid,o,a,flag=0,min=n;
	if(checkAll(A,r)==0 || (prep+m)>n)
	{
		//debug3(prep,m,n);
		cout << "-1" << "\n";
		return 0;
	}
	while(l<=r)
	{
		mid=l+(r-l)/2;
		//debug3(l,r,mid);
		o=checkOrder(A,mid);
		a=checkAll(A,mid);
		//debug2(o,a);	
		if(o==1 && a==1 && A[mid]!=0 )
		{
			flag=1;
			r=mid-1;
			if(min>mid)
			{
				min=mid;
			}
		}
		else if(o==1 && a==1 && A[mid]==0)
		{
			r=mid-1;
		}
		else if(o==0 || a==0)
		{
			l=mid+1;
		}
	}
	if(flag==1)
	{
		cout << (min+1) << "\n";
	}
	else
	{
		cout << "-1" << "\n";
	}
	return 0;
}
