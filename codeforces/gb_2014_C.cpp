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
	int n,m;
	sd2(n,m);
	int weight[n], days[m];
	f(i,n)
	{
		sd(weight[i]);
	}
	f(i,m)
	{
		sd(days[i]);
	}

	// stack + hashing 
	int last_read[n];
	f(i,n)
	{
		last_read[i]=INT_MIN;
	}

	int ans=0;
	unordered_set<int> S;
	f(i,m)
	{
		S.clear();
		if(last_read[days[i]-1]==INT_MIN)
		{
			f(j,i)
			{
				if(S.find(days[j]-1)!=S.end())
				{
					continue;
				}
				S.insert(days[j]-1);
				ans+=weight[days[j]-1];
			}
			last_read[days[i]-1]=i;
		}
		else
		{
//			cout << last_read[days[i]-1]+1 << " " << i-1 << "\n";
			fl(j,last_read[days[i]-1]+1,i-1)
			{
				if(S.find(days[j]-1)!=S.end())
				{
					continue;
				}	
				S.insert(days[j]-1);
				ans+=weight[days[j]-1];
			}
			last_read[days[i]-1]=i;
		}

	}
    cout << ans << "\n";
	return 0;
}
