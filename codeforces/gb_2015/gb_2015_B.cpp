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

bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}

const int N=59,M=1770;
int main()
{
	ll array[N+1];
	array[0]=1;
	f(i,N)
	{
		array[i+1]=2*array[i];
	}
	ll values[M];
	f(i,M)
	{
		values[i]=-1;
	}

	ll sum=0;
	f(i,N+1)
	{
		//cout << i << " " << array[i] << "\n";
		sum+=array[i];
	}

	//debug(sum);
	ll temp=0;
	int k=0;
	for(int i=N;i>=1;i--)
	{
		for(int j=0;j<=(i-1);j++)
		{
			temp=sum-array[j];
			values[k]=temp;
			k++;
		}
		sum-=array[i];
	}

	ll  a,b,count=0;
	cin >> a >> b;
	f(i,M)
	{
		if(a<=values[i] && b>=values[i])
		{
			count++;
		}
	}
    cout << count;
	return 0;
}
