#include<cstdio>
#include<iostream>
#include<cmath>

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

#define ll long long int

int main()
{
	int k2,k3,k5,k6;
	sd2(k2,k3);
	sd2(k5,k6);

	int p56 = (k5>k6)?k6:k5;
	int p3 = k3;

	int n256 = (p56>k2)?k2:p56;

	if(n256==k2)
	{
		cout << 256*n256 << "\n";
	}
	else
	{
		int n32 = ((k2-p56)>p3)?p3:(k2-p56);
		cout << 256*n256+n32*32 << "\n";
	}
	return 0;
}
