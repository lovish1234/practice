#include<stdio.h>

int main()
{
	long long int n,x,ans;
	if (scanf("%lld\n",&n)==1 && scanf("%lld\n",&x)==1 ) 
	{
		ans=n/x;
		if(n%x==0)
		{
			printf("%lld\n",ans);
		}
		else
		{
			printf("%lld\n",ans+1);
		}
	}
	return 0;
}
