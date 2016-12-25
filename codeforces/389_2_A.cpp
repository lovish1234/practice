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
	int n,m,k;
	sd3(n,m,k);

	int lane, desk;
	char side;

	lane = ((k%(2*m))==0)? (k/(2*m)):((k/(2*m))+1);
	side = (((k%(2*m))%2)==0)?'R':'L';
	desk = ((k%(2*m)==0))?m:(side=='R'?((k%(2*m))/2):(((k%(2*m))/2)+1));
	cout << lane << " " << desk << " " << side << "\n";
	return 0;
}
