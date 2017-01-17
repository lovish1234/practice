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
	int n,k;
	sd2(n,k);

	int a,b,i=0,j=0,l=0,x,y;
	sd2(a,b);
    
	char c,d;
	if(a>=b)
	{
		x=a;y=b;
		c='G';
		d='B';
	}
	else
	{
		x=b;y=a;
		c='B';
		d='G';
	}

	string s;
//	cout << a << " " << b << "\n";
	while(i<n)
	{
		if(x==0)
		{
			break;
		}
		if(j==0)
		{
			l=0;
		    while(l<k)
		    {
//				cout << x << " " << i << " " << "\n"; 

				if(x==0)
				{
					break;
				}
				s+=c;
                x--;l++;i++;
			}
//			cout << s << "\n";
			j=1;
		}
		else
		{
			if(y==0)
			{
				break;
			}
			s+=d;
			j=0;
//			cout << s << "\n";
			i++;y--;
		}
	
	}

	if(s.length()==n)
	{
		cout << s;
	}
	else
	{
		if(x==0 && y<k)
		{
			while(y>0)
			{
				s+=d;
				y--;
			}
			cout << s;
		}
		else if(y==0 && x<k && s[s.length()-1]!=c)
		{
			while(x>0)
			{
				s+=c;
				x--;
			}
			cout << s;
		}
		else
		{
			cout << "NO";
		}
	}
	return 0;
}
