#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<unordered_set>

using namespace std;

#define sd(a) scanf("%d",&a)
#define sd2(a) scanf("%d%d",&a,&b)
#define sd3(a) scanf("%d%d%d",&a,&b,&c)

#define f(i,n) for(int i=0;i<n;i++)
#define fl(i,a,b) for(int i=a;i<=b;i++)


#define ll long long int

int main()
{
	string s;
	cin >> s;
	int n = s.size(),count=1;
	unordered_set<string> H;
	H.insert(s);
	f(i,n-1)
	{		
		char temp = s.back();
		s.pop_back();
		s.insert(0,1,temp);
//		cout << s << "\n";
		if(H.find(s)==H.end())
		{
			H.insert(s);
			count++;
		}
	}
    cout << count;

	return 0;
}
