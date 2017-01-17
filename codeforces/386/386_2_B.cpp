#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<list>

using namespace std;

#define sd(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define f(i,n) for(int i=0;i<n;i++)
#define fl(i,a,b) for(int i=a;i<=b;i++)

#define  mz(array)  memset(array,0,sizeof(array))

#define ll long long int

int main()
{
	int n;
	sd(n);

	string s,ans;
	cin >> s;
    int position=0;

	for(int i=s.length()-1;i>=0;i--)
	//for( reverse_iterator rit= s.rbegin(); rit!=s.rend(); ++rit )
	{
		ans.insert(position,1,s[i]);
		position= (ans.length()/2);
	}
    cout << ans;


}
