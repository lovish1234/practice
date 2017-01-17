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

#define ll long long int

int main()
{
	int n,q;
	sd2(n,q);
    
	int time[q], resources[q],duration[q];
	f(i,q)
	{
		sd3(time[i],resources[i],duration[i]);
		time[i]-=1;
	}

	// last field to store number of unavailable servers

	int N = 1001005;
	int log[N][n+1];
    f(i,N)
	{
		f(j,n+1)
		{
			log[i][j]=0;
		}
	}
    
	int sumserver=0,occupied=0;
	// for ith task
	f(i,q)
	{
		// checking if there are enough servers resources[i] available for ith task at
		// time[i]. if yes, allot these for duration[i], otherwise ignore the
		// task
		//cout << time[i] << duration[i] << resources[i] << "\n";
        
		if((n-log[(time[i])][n])>=resources[i])
		{
			sumserver=0,occupied=0;
			f(j,n)
			{
                //cout << log[3][0]  << " " << log[3][1] << "\n";
			    // get a free server with lowest index
				//cout << time[i] << " " << j << " " << log[time[i]][j] << "\n";
				if(log[(time[i])][j]==0 )
				{
					//cout << j+1 << "\n";
					sumserver+=(j+1);
					// occupy it for duration[i]
					for(int k=(time[i]);k<=(time[i]+duration[i]-1);k++)
					{
						log[k][j]=1;
						log[k][n]+=1;
						//cout << k << " " << j << " " << log[k][j] << "\n";
						//cout << k << " " << n << " " << log[k][n] << "\n";
					}
					occupied++;
				}
				//cout << occupied << resources[i] << "\n";
				if(occupied==resources[i])
				{
					cout << sumserver << "\n";
					break;
				}
	
			}

		}
		else
		{
			cout << "-1" << "\n";
		}
	}
	

    return 0;
}
