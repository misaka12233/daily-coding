#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
const ll mod = 1e9 + 7; 
int n, i, j, x, y;
ll fac[maxn], inv[maxn], p2[maxn];
ll C(int n, int m)
{
	if (m > n || m < 0) return 0;
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
	int T;
	scanf("%d", &T);
	fac[0] = inv[0] = p2[0] = 1;
	fac[1] = inv[1] = 1;
	p2[1] = 2;
	for (int i = 2; i <= 100; i++)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		p2[i] = p2[i - 1] * 2 % mod;
	}
	for (int i = 1; i <= 100; i++)
		inv[i] = inv[i - 1] * inv[i] % mod;
	while (T--)
	{
		scanf("%d%d%d%d%d", &n, &i, &j, &x, &y);
		if (x > y)
		{
			swap(i, j);
			swap(x, y);
		}
		ll ans = 0;
		ans = (ans + C(x - 1, x - i) * C(y - x - 1, (y - j) - (x - i))) % mod;
		ans = (ans + C(x - 1, n - i) * C(y - x - 1, (y - j) - (n - i) - 1)) % mod;
		if (y != n)
		{
			ans = (ans + C(x - 1, x - i) * C(y - x - 1, (n - j) - (x - i))) % mod;
			ans = (ans + C(x - 1, n - i) * C(y - x - 1, (n - j) - (n - i) - 1)) % mod;
			ans = ans * p2[n - y - 1] % mod;
		}
		if (x == i && y == j) ans = (ans - 1 + mod) % mod;
		if (n - x + 1 == i && n - y + 1 == j) ans = (ans - 1 + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}

