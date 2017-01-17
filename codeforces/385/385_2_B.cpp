#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

#define sd(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define f(i,n) for(int i=0;i<n;i++)
#define fl(i,a,b) for(int i=a;i<=b;i++)


#define ll long long int

int main()
{
	int n,m;
	sd2(n,m);

	int array[n][m];
	char temp;
	int minX=n,maxX=-1,maxY=-1,minY=m;
	f(i,n)
	{
		f(j,m)
		{
			cin >> temp;
			if(temp=='X')
			{
				array[i][j]=1;
				if(i>maxX)
				{
					maxX=i;
				}
				if(i<minX)
				{
					minX=i;
				}
				if(j>maxY)
				{
					maxY=j;
				}
				if(j<minY)
				{
					minY=j;
				}
			}
			else if(temp=='.')
			{
				array[i][j]=0;
			}
			//cout << array[i][j];
		}
		//cout << "\n";
	}
	// symmytry in a 2D array
	// max and min of vertical and horizontal directions
	fl(i,minX,maxX)
	{
		fl(j,minY,maxY)
		{
			if(array[i][j]==0)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}
