#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

#include<string>
#include<list>
#include<queue>
#include<unordered_map>
#include<unordered_set>


using namespace std;

#define sd(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define fr(n,i) for(int i=(n-1);i>=0;i--)
#define fabr(i,b,a) for(int i=b;i>=a;i--)

#define debug(a) cout<< a << "\n"
#define debug2(a,b) cout << a << " " << b << "\n"
#define debug3(a,b,c) cout << a << " " << b << " " << c << "\n"

#define  mz(array)  memset(array,0,sizeof(array))

#define mp make_pair
#define F first
#define S second
#define pb push_back

#define ll long long int

bool comparator(pair< ll,ll > const& a, pair< ll,ll > const& b)
{
	return a.S < b.S;
}

int n,m;
vector<int> A,B,P(0),LM;
int possibleOrNot(vector<int> A, int i, int n, vector<int> B, int j, int m)
{
	//cout << i << n << j << m;
	// check if global sum not equal
	if(i==n && j==m)
	{
		return 1;
	}
	if((i==n && j!=m) || (i!=n && j==m))
	{
		return 0;
	}

	// check if local sum is not equal
	int temp=B[j],k=i;
	while(temp>0)
	{
		temp-=A[k];
		k++;
	}
	if(temp<0)
	{
		return 0;
	}

	// check if one of values in the prefix is different from all others 
	int allEqual=1;
	fab(l,i,k-2)
	{
		if(A[l]!=A[l+1])
		{
			allEqual=0;
		}
	}
	if(allEqual==1 && k!=(i+1))
	{
		return 0;
	}

//	cout << k << "\n";
	P.pb(k);
	return (1 && possibleOrNot(A,k,n,B,j+1,m));
}

void getLocalMaxima()
{
	int l,h;
	f(i,m)
	{
		int max=0,maxi=-1;
		l=P[i];
		h=P[i+1];
		if(l==(h-1))
		{
			max=A[l];
			maxi=l;
			LM.pb(maxi);
			continue;
		}

		fab(j,l,h-1)
		{
			if(A[j] >= max)
			{
		//		cout << j << "\n";
		//		cout << max << "\n";
				if(j==l)
				{
					if(A[j]>A[j+1])
					{
//						cout << "h~1";
						max=A[j];
						maxi=j;
					}
				}
				else if(j==(h-1))
				{
					if(A[j]>A[j-1])
					{
//						cout << "h~2";
						maxi=j;
						max=A[j];
					}
				}
				else if(j!=l && j!=(h-1))
				{
//					cout << "h~3x" << A[j] << A[j-1] << A[j+1] << (A[j] > A[j-1]) <<  (A[j] >A[j+1]) << "\n";

					if(((A[j] == A[j-1]) && (A[j] > A[j+1])) || (A[j] >  A[j-1]) && (A[j] == A[j+1])) 
					{
//						cout << "h~3" << A[j] << A[j-1] << A[j+1] << (A[j] > A[j-1]) <<  (A[j] >A[j+1]) << "\n";
						maxi=j;
						max=A[j];
					}
				}
			}
//			cout << max << " " << maxi << "\n";
		}
		LM.pb(maxi);
	}
}

void printOrder()
{
	int l,h,lm;
	f(i,m)
	{
		l=P[i];
		h=P[i+1];
		lm=LM[i];
		if(l==(h-1))
		{
			continue;
		}
		else 
		{
			if(l==lm)
			{
				fab(j,l+1,h-1)
				{
					cout << l+1+i-l <<  " R" << "\n";
				}
			}
			else if((h-1)==lm)
			{
				fabr(j,h-1,l+1)
				{
					cout << j+1+i-l <<  " L" << "\n";
				}
			}
			else
			{
				if(A[lm]>A[lm-1])
				{
					fabr(j,lm,l+1)
					{
						cout << j+1+i-l << " L" << "\n";
					}
					fab(j,lm+1,h-1)
					{
						cout << l+1+i-l << " R" << "\n";
					}
				}
				else
				{
					fab(j,lm+1,h-1)
					{
						cout << lm+1+i-l << " R" << "\n";
					}
					fabr(j,lm,l+1)
					{
						cout << j+1+i-l << " L" << "\n";
					}
				}
			}
		}
	}
}


int main()
{
	int temp;
	cin >> n;
	f(i,n)
	{
		cin >> temp;
		A.pb(temp);
	}

	cin >> m;
	f(i,m)
	{
		cin >> temp;
		B.pb(temp);
	}

	P.pb(0);
	if(possibleOrNot(A,0,n,B,0,m)==0)
	{
		cout << "NO" << "\n";
		return 0;
	}
	else
	{
		cout << "YES" << "\n";
	}

	getLocalMaxima();
//	debug3(P[0],P[1],LM[0]);
	printOrder();
/*
	vector<int>:: iterator it;
	cout << "\n";
	for(it=P.begin();it!=P.end();++it)
	{
		cout << *it << " ";
	}
	cout << "\n";
	for(it=LM.begin();it!=LM.end();++it)
	{
		cout << *it << " ";
	}
*/	

	return 0;
}
