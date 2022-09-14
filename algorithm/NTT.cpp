#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 33554432 + 10;
const ll mod = 998244353;

ll fastpow(ll x, ll k)
{
	ll res = 1;
	while (k)
	{
		if (k & 1) res = res * x % mod;
		k >>= 1;
		x = x * x % mod;
	}
	return res;
}
ll g = 3, gi = fastpow(3, mod - 2);
int num[maxn], lim, l;
void NTT(int *s, bool op)
{
	for (int i = 0; i < lim; i++)
		if (i < num[i])
			swap(s[i], s[num[i]]);
	for (int len = 1; len < lim; len <<= 1)
	{
		ll wn = fastpow(op ? g : gi, (mod - 1) / (len << 1));
		for (int i = 0; i < lim; i += (len << 1))
		{
			ll w = 1;
			for (int j = 0; j < len; j++, w = w * wn % mod)
			{
				ll x = s[i + j], y = w * s[i + j + len] % mod;
				s[i + j] = (x + y) % mod;
				s[i + j + len] = ((x - y) % mod + mod) % mod;
			}
		}
	}
}
void sol(int *a, int n, int *b, int m)
{
	lim = 1;
	l = 0;
	while (lim <= n + m)
	{
		lim <<= 1;
		l++;
	}
	for (int i = 0; i < lim; i++)
		num[i] = (num[i >> 1] >> 1) | ((i & 1) << (l - 1));
	NTT(a, true);
	NTT(b, true);
	for (int i = 0; i < lim; i++)
		a[i] = 1ll * a[i] * b[i] % mod;
	NTT(a, false);
	ll tmp = fastpow(lim, mod - 2);
	for (int i = 0; i < lim; i++)
		a[i] = 1ll * a[i] * tmp % mod;
}

int n;
int q;
int c[15];
int fac[maxn];
int qry[310];
int a[maxn], b[maxn];
int w;
int inv(int x)
{
	return fastpow(fac[x], mod - 2);
}
int main()
{
	scanf("%d", &w);
	for (int i = 0; i < w; i++)
		scanf("%d", c + i);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
		scanf("%d", qry + i), n = max(n, qry[i]);
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	for (int i = c[0]; i <= n; i++) a[i] = inv(i);
	for (int i = 1; i < w; i++)
	{
		for (int j = 0; j < c[i]; j++) b[j] = 0;
		for (int j = c[i]; j <= n; j++) b[j] = inv(j);
		sol(a, n, b, n);
		for (int j = n + 1; j < lim; j++) a[j] = b[j] = 0;
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", 1ll * a[qry[i]] * fac[qry[i]] % mod);
	return 0;
}

