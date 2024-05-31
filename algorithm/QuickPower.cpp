#include<bits/stdc++.h>
using namespace std;
int quickPower(int x, int y, int mod)
{
	int res = 1;
	while (y)
	{
		if (y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}
int main()
{
	int n, e, x;
	scanf("%d%d%d", &n, &e, &x);
	printf("%d\n", quickPower(x, e, n));
	return 0;
}

