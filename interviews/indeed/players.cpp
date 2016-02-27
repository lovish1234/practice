#include<cstdio>
#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

int main()
{
	int h,w;
	scanf("%d\n",&h);
	scanf("%d\n",&w);
	vector< vector <char> > B;
	vector< char > temp;
	unordered_map <char, pair<int,int> > H;
	
	char c;
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
	
	int firstIndex,secondIndex;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(H.find(B[i][j])==H.end())
			{
				H[B[i][j]]=make_pair(i,j);
			}
			else
			{
				firstIndex=H[B[i][j]].first;
				secondIndex=H[B[i][j]].second;
				if((firstIndex+secondIndex)>(i+j))
				{
					H[B[i][j]]=make_pair(i,j);
				}
			}
		}
	}
	unordered_map<char, pair<int,int> >::iterator iter;
	for(iter=H.begin();iter!=H.end();++iter)
	{
		cout << iter->first << " " << (iter->second.first)+1 << " " << (iter->second.second)+1 << "\n";
	}
		
	
	return 0;
}
