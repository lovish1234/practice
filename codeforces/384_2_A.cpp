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


int main()
{
	int n,a,b;
	sc3(n,a,b);

	string s;
	cin >> s;

	int array[n];
	for(int i=0;i<n;i++)
	{
		array[i] = s[i] - '0';
	}
    // little thinking leads to the fact that
	// answer can be either 0 or 1
	if(array[a-1]==array[b-1])
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}

	return 0;
}

