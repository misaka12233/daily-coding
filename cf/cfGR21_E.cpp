#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
const ll mod = 1e9 + 7;
int n;
ll fac[maxn << 1], inv[maxn << 1];
ll fastPow(ll x, int p)
{
	ll res = 1;
	while (p)
	{
		if (p & 1) res = res * x % mod;
		p >>= 1;
		x = x * x % mod;
	}
	return res;
}
ll C(int n, int m)
{
	return fac[n] * inv[n - m] % mod * inv[m] % mod;
}
int main()
{
	scanf("%d", &n);
	ll x;
	scanf("%lld", &x);
	fac[0] = 1;
	inv[0] = 1;
	for (ll i = 1; i <= x + n; i++)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = fastPow(fac[i], mod - 2);
	}
	ll ans = x;
	for (ll i = 1; i <= n; i++)
	{
		scanf("%lld", &x);
		if (x == 0) continue;
		ans = (ans + C(i + x, i + 1)) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}

