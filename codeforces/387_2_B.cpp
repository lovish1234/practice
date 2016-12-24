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
	int n;
	sd(n);

	string s;
	cin >> s;

	if(((s.length())%4)!=0)
	{		
		cout << "===";
		return 0;
	}


    unordered_map<char,int> M;
	M.insert(mp('A',0));
	M.insert(mp('G',0));
	M.insert(mp('C',0));
	M.insert(mp('T',0));
	M.insert(mp('?',0));
	f(i,n)
	{
		M[s[i]]++;
	}

	int maxval=-1;
	typedef unordered_map<char,int>::iterator it_type;
	for( it_type iterator = M.begin(); iterator!=M.end();iterator++)
	{
		if(iterator->first!='?' && (iterator->second)>maxval)
		{
			maxval=iterator->second;
		}
	}

    int sum =0,sumq=0;
	for( it_type iterator = M.begin(); iterator!=M.end();iterator++)
	{
		if(iterator->first!='?')
		{
		    (iterator->second)=maxval-(iterator->second);
			sum+=(iterator->second);
	    }
		else
		{
			sumq=iterator->second;
		}
	}

	// if questions cannot be filled by remaining symbols
	int extra = (sumq-sum)/4;
	if(((sumq-sum)%4)!=0 || sumq<sum)
	{
		cout << "===";
		return 0;
	}
	for( it_type iterator = M.begin(); iterator!=M.end();iterator++)
	{
		if(iterator->first!='?')
		{
		    (iterator->second)=extra+(iterator->second);
	    }
	
	}


	it_type iterator = M.begin();
	int i=0;
	while ( i< s.length() && iterator!=M.end())
	{
		if(iterator->first=='?' || iterator->second==0)
		{
			iterator++;
			continue;
		}
		if(s[i]!='?')
		{
			i++;
			continue;
		}
		s[i]=iterator->first;
		(iterator->second)--;
		i++;
	}
    
	f(i,s.length())
	{
		cout << s[i];
	}

	return 0;
}
