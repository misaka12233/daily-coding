#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int p, q;
int n, m;
int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
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
	scanf("%d%d", &p, &q);
	n = p * q;
	m = (p - 1) * (q - 1);
	for (int x = 1; x <= n; x++)
	{
		for (int e = 2; e < m; e++)
		{
			if (gcd(e, m) != 1) continue;
			int tmp = quickPower(x, e, n);
			if (tmp == x)
				printf("%d %d\n", x, e);
		}
	}
	return 0;
}

