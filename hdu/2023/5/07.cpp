#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 10;
const int mod = 998244353;
ll mul(ll a, ll b)
{
	return a * b % mod;
}
ll add(ll a, ll b)
{
	return (a + b) % mod; 
}
ll sub(ll a, ll b)
{
	return (a - b + mod) % mod; 
}
ll qpow(ll a, int b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

ll p1[maxn], p2[maxn];
ll fac[maxn], inv[maxn];
ll C(int n, int k)
{
	return mul(fac[n], mul(inv[k], inv[n - k]));
}
void sol()
{
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	ll p = mul(a, qpow(b, mod - 2));
	ll sum = 0, ans = 0;
	p1[0] = p2[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		p1[i] = mul(p1[i - 1], p);
		p2[i] = mul(p2[i - 1], sub(1, p));
	}
	for (int i = 1; i <= n; i++)
	{
		sum = add(sum, qpow(i, m));
		ans = add(ans, mul(mul(p1[i], p2[n - i]), mul(sum, C(n, i))));
	}
	printf("%lld\n", ans);
}
int main()
{
	fac[0] = inv[0] = 1;
	fac[1] = inv[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mod - (mod / i) * inv[mod % i] % mod;
	}
	for (int i = 2; i <= 1000000; i++)
		inv[i] = mul(inv[i], inv[i - 1]);
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

