#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int calculateSum(vector< vector< int> > &B)
{
	int sum=0;
	for(int i=0;i<B.size();i++)
	{
		for(int j=0;j<B[0].size();j++)
		{
			sum+=B[i][j];
		}
	}
	return sum;
}	

vector <int> sumRows(vector< vector < int> > &B)
{
	vector <int> result;
	int ans;
	for(int i=0;i<B.size();i++)
	{
		ans=0;
		for(int j=0;j<B[i].size();j++)
		{
			ans+=B[i][j];
		}
		cout << ans << " ";
		result.push_back(ans);
	}
	cout << "\n";
	return result;
}


vector <int> sumColumns(vector< vector < int> > &B)
{
	vector <int> result;
	int ans;
	for(int i=0;i<B[0].size();i++)
	{
		ans=0;
		for(int j=0;j<B.size();j++)
		{
			ans+=B[j][i];
		}
		cout << ans << " ";
		result.push_back(ans);
	}
	cout << "\n";
	return result;
}



int main()
{
	int h,w,x,k;
	scanf("%d\n",&h);
	scanf("%d\n",&w);
	scanf("%d\n",&x);
	scanf("%d\n",&k);
	vector< vector <int> > B;
	vector< int > temp;
	
	int c;
	for(int i=0;i<h;i++)
	{
		temp.clear();
		for(int j=0;j<w;j++)
		{
			cin >> c;
			temp.push_back(c);
		}
		B.push_back(temp);
	}
	vector <int> sRow,sColumn;
	while(k!=0)
	{
		sRow=sumRows(B);
		sColumn=sumColumns(B);


		k--;
	}
	return 0;
}
	
