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
	int n,t;
	sd2(n,t);

	int array[n-1];
	f(i,n-1)
	{
		sd(array[i]);
	}

	int i=0;
	while(i<(t-1))
	{
//		cout << i << "\n";
		i+=(array[i]);
	}

//	cout << i << " " << (t-1) << "\n";
	if(i==(t-1))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}
