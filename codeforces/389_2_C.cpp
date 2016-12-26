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

int l=0,r=0,u=0,d=0;

void reset()
{
	l=0,r=0;
	u=0,d=0;
	return;
}
int main()
{
	int n;
	sd(n);

	string s;
	cin >>s;

	int count=0;

	f(i,n)
	{
		if(s[i]=='R')
		{
			if(l==1)
			{
				count++;
				reset();
				r=1;
			}
			else
			{
			    r=1;
			}
		}
		else if(s[i]=='L')
		{
			if(r==1)
			{
				count++;
				reset();
				l=1;
			}
			else
			{
			    l=1;
			}
	
		}
		else if(s[i]=='U')
		{
			if(d==1)
			{
				count++;
				reset();
				u=1;
			}
			else
			{
				u=1;
			}
		}
		else if(s[i]=='D')
		{
			if(u==1)
			{
				count++;
				reset();
				d=1;
			}
			else
			{
				d=1;
			}	
		}

	}

	cout << (count+1) << "\n";
	return 0;
}
