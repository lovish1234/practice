#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)

int main()
{
	int x1, y1, x2, y2, x3, y3, x4, y4;
	sc2(x1,y1);sc2(x2,y2);sc2(x3,y3);

	//int theta1 = ((y2-y1)/(x2-x1))*((y3-y2)/(x3-x2));
	//int theta2 = ((y3-y2)/(x3-x2))*((y1-y3)/(x1-x3));
	//int theta3 = ((y1-y3)/(x1-x3))*((y2-y1)/(x2-x1));

	cout << "3\n";
	x4 = x2+x3-x1, y4= y2+y3-y1;
	cout << x4 << " " << y4 << "\n";

	x4 = x1+x3-x2, y4= y1+y3-y2;
	cout << x4 << " " << y4 << "\n";

	x4 = x2+x1-x3, y4= y2+y1-y3;
	cout << x4 << " " << y4 << "\n";

	return 0;
}

