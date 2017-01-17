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
	int n;
	sd(n);

	string s;
	cin >> s;

	int a=0,d=0;
	f(i,n)
	{
		if(s[i]=='A')
		{
			a++;
		}
		else if(s[i]=='D')
		{
			d++;
		}
	}

	if(a==d)
	{
		cout << "Friendship";
	}
	else if(a>d)
	{
		cout << "Anton";
	}
	else if(a<d)
	{
		cout << "Danik";
	}

	return 0;
}
