#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exgcd(b, a % b, y, x);
	y = y - a / b * x;
	printf("%d*%d + %d*%d = %d\n", x, a, y, b, gcd);
	return gcd;
}
int main()
{
	int a, b, x, y;
	scanf("%d%d", &a, &b);
	exgcd(a, b, x, y);
	return 0;
}

