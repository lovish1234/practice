#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstdint>
#include<limits.h>

using namespace std;

int maxsum=INT_MIN;

void getSets(int** board, int h, int w, int x, int k, int j_prev, int i_prev)
{
	int i,j,temp_w[w],temp_h[h];	
	if(k==0 || (j_prev==(w) && i_prev==(h)))
	{
		int sum=0;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				sum+=board[i][j];
			}
		}
		//cout << sum << "\n";
		if(sum>maxsum)
		{
			maxsum=sum;
		}
		return;
	}
	
	for(i=i_prev;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			temp_w[j]=board[i][j];
			board[i][j]=x;
		}
		getSets(board, h, w, x, k-1, i+1, j_prev);
		for(j=0;j<w;j++)
		{
			board[i][j]=temp_w[j];
		}
	}
	
	for(j=j_prev;j<w;j++)
	{
		for(i=0;i<h;i++)
		{
			temp_h[i]=board[i][j];
			board[i][j]=x;
		}
		getSets(board, h, w, x, k-1, i_prev, j+1);
		for(i=0;i<h;i++)
		{
			board[i][j]=temp_h[i];
		}
	}
		
}

int main()
{
	int h,w,x,k,i,j;
	cin >> h >> w >> x >> k;
	int ** board=(int**)malloc(sizeof(int*)*h);
	for(int i=0;i<h;i++)
	{
		board[i]=(int*)malloc(sizeof(int)*w);
	}
	
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>> board[i][j];
		}
	}

	getSets(board, h, w, x, k, 0, 0);
	cout << maxsum << "\n";
	return 1;
}
