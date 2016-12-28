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

#define ll long long int

bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.first < b.first;
}

int N = 5000;

int main()
{
	int n;
	sd(n);

	int array[N];
	f(i,N)
	{
		array[i]=0;
	}
    array[N-1]=1;

	f(j,n)
	{
		int carry=0;
		for(int i=N-1;i>=0;--i)
		{
			int current = carry + array[i]*2;	
			carry=0;
			while(current>=10)
			{
				carry+=1;
				current-=10;
			}
			array[i]=current;
		}
	}

    string output;
	f(i,N)
	{
		if(output.length()>0 || array[i]>0)
		{
   			output+=(array[i]+'0');
		}
	}
	cout << output;

	return 0;
}
