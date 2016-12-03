#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)

int main()
{
	long long int n;
	int ans=0;
	cin >> n;

	long long int t[100];
    t[0]=2,t[1]=3;
	
    if( n==2)
	{
		cout << "1\n";
		return 0;
	}
	else if(n==3 || n==4)
	{
		cout << t[0];
		return 0;
	}
    
	for(int i=2;i<90;i++)
	{
		t[i]=t[i-1]+t[i-2];
		if(t[i]>n)
		{
			ans = i;
			cout << ans;
			return 0;
		}
	}

    return 0;
}

