#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
double r, x, y, d, dis; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf%lf%lf%lf", &r, &x, &y, &d);
		dis = sqrt(x * x + y * y);
		double a = acos((dis + d) / r), b = acos((dis - d) / r);
		printf("%.9f\n", (b - a) * r);
	}
	return 0;
}

