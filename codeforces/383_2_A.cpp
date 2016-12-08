#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int flag=(n%4);
	if (n==0)
	{
		cout << "1\n";
		return 0;
	}
	else if(flag==0 )
	{
		cout << "6\n";
	}
	else if(flag==1 )
	{
		cout << "8\n";
	}
	else if(flag==2)
	{
		cout << "4\n";
	}
	else if(flag==3 )
	{
		cout << "2\n";
	}
	return 0;
}

