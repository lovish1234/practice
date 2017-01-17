#include<unordered_map>
#include<cstdio>
#include<iostream>

using namespace std;

#define  ll long long 

int main()
{
    int n, k;
	ll ans=0;
	scanf("%I64d %I64d",&n,&k);
    
	int array[n];
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&array[i]);
	}

    unordered_map<int,ll> H;
	for(int i=0;i<n;i++)
	{
        if(H.find(array[i])!=H.end())
		{
			H[array[i]]++;
		}
		else
		{
		    H.insert(make_pair(array[i],1));
		}
	}

	for(int i=0;i<n;i++)
	{
		if(H.find(array[i]^k)!=H.end())
		{
			if((array[i]^k)!=array[i])
			{
				ans+=H[array[i]^k];
			}
			else
			{
				ans+=(H[array[i]^k]-1);
			}
		}
	}
	cout << ans/2 << "\n";
	return 0;
}

	
