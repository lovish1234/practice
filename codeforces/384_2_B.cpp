#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ss(a) scanf("%s",a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)

#define ll long long int 


int getNum( ll n, ll k)
{
	ll temp = pow(2,n-1);
	if(k==temp)
	{
		return n;
	}
	else if(k<temp)
	{
		return getNum(n-1,k);
	}
	else if(k>temp)
	{
		return getNum(n-1, k-temp);
	}
}

int main()
{
	ll n,k;
	cin >> n >> k;
    cout << getNum(n,k);
	return 0;
}
