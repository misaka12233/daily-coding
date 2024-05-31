#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxc = 200000 + 10;
const int maxn = 10000000 + 10;
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
void sol(int n, int *b, int m)
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
	NTT(b, true);
}
void getans(int *a, int *b)
{
	NTT(a, true);
	for (int i = 0; i < lim; i++)
		a[i] = 1ll * a[i] * b[i] % mod;
	NTT(a, false);
	ll tmp = fastpow(lim, mod - 2);
	for (int i = 0; i < lim; i++)
		a[i] = 1ll * a[i] * tmp % mod;
}

int n, q;
int c[15];
int fac[maxn], inv[maxn];
int qry[310];
int a[11][maxc], b[maxc], tmp[11][maxc];
int w;
int main()
{
	scanf("%d", &w);
	for (int i = 0; i < w; i++)
		scanf("%d", c + i);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
		scanf("%d", qry + i), n = max(n, qry[i]);
	fac[0] = inv[0] = 1;
	fac[1] = inv[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fac[i] = 1ll * fac[i - 1] * i % mod;
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * inv[i] * inv[i - 1] % mod;
	for (int i = 0; i < c[0]; i++)
		a[0][i] = (mod - inv[i]) % mod;
	a[1][0] = 1;
	int now = c[0] - 1;
	for (int i = 1; i < w; i++)
	{
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= now; k++)
				tmp[j + 1][k] = a[j][k];
		for (int k = 0; k < c[i]; k++)
			b[k] = (mod - inv[k]) % mod;
		sol(now, b, c[i] - 1);
		for (int j = 0; j <= i; j++)
			getans(a[j], b);
		for (int j = 1; j <= i + 1; j++)
			for (int k = 0; k <= now; k++)
				a[j][k] = (a[j][k] + tmp[j][k]) % mod;
		now += c[i] - 1;
		for (int k = 0; k < lim; k++)
			b[k] = 0;
	}
	for (int i = 1; i <= q; i++)
	{
		int ans = 0;
		if (qry[i] <= now) ans = a[0][qry[i]];
		for (int j = 1; j <= w; j++)
		{
			int pj = fastpow(j, qry[i]), invj = fastpow(j, mod - 2);
			for (int k = 0; k <= min(now, qry[i]); k++, pj = 1ll * pj * invj % mod)
			{
			 	int t = 1ll * a[j][k] * inv[qry[i] - k] % mod;
				t = 1ll * t * pj % mod;
			 	ans = (ans + t) % mod;
			}
		}
		printf("%d\n", 1ll * ans * fac[qry[i]] % mod);
	}
	return 0;
}
/*
10
113 76 160 108 30 66 168 41 176 62
1
800547
*/

