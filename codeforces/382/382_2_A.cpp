#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;



int main()
{
	int n,k;
	cin >> n >> k;
    string S;
	cin >> S;
    
	int target, initial;
	target = S.find('T');
	initial = S.find('G');
    
	if(int(abs(target-initial)%k)!= 0)
	{
		cout << "NO";
	}
	else
	{
		int tempI = (target>initial)?initial:target;
		int tempT = (target<initial)?initial:target;
		int i=1;
		while( i<int(abs(target-initial)/k))
		{
			if(S[tempI+i*k]=='#')
			{
				cout << "NO";
				return 0;
			}
			i++;
		}
		cout << "YES";
    }
	return 0;
}

