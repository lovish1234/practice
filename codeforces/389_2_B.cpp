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

int main()
{
	string s;
	cin >> s;

	string t;
	cin >> t;
    
	int len= s.length();

	unordered_map<char,char> M,N;

	f(i,len)
	{
		if(M.find(s[i])==M.end())
		{
            if(N.find(t[i])==N.end())
			{
			    M.insert(mp(s[i],t[i]));
			    N.insert(mp(t[i],s[i]));
				N.insert(mp(s[i],t[i]));
			}
			else
			{
				if(N[t[i]]!=s[i])
				{
					cout << -1 << "\n";
					return 0;
				}
			}
		}
		else
		{
			if(M[s[i]]!=t[i])
			{
				cout << -1 << "\n";
				return 0;
			}
		}
	}
    
    typedef unordered_map<char,char>::iterator it_type;
    it_type iterator = M.begin(),toErase;

    while(iterator!=M.end())
	{
		if((iterator->first)==(iterator->second))
		{
			toErase = iterator;
			++iterator;
			M.erase(toErase);
		}
		else
		{
			++iterator;
		}
	}

	cout << M.size() << "\n";

	for( it_type iterator = M.begin(); iterator!=M.end();iterator++)
	{
		cout << (iterator->first) << " " << (iterator->second) << "\n";
	}
	
	return 0;
}


