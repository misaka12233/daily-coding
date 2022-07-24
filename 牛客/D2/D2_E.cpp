#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 4000000 + 10;
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
void NTT(ll *s, bool op)
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
				s[i + j + len] = (x - y + mod) % mod;
			}
		}
	}
}
void sol(ll *a, int n, ll *b, int m)
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
		a[i] = a[i] * b[i] % mod;
	NTT(a, false);
	ll tmp = fastpow(lim, mod - 2);
	for (int i = 0; i < lim; i++)
		a[i] = a[i] * tmp % mod;
}

int n;
ll fac[maxn], inv[maxn];
ll C(int m, int n)
{
	return fac[n] * inv[m] % mod * inv[n - m] % mod; 
}
ll p[maxn], q[maxn], f[maxn];
int main()
{
	scanf("%d", &n);
	fac[0] = inv[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = fastpow(fac[i], mod - 2);
	}
	for (int i = 0; i <= n; i++)
	{
		if (n >= 3 * i)
			f[i] = C(i, n - 2 * i) * fastpow(26, n - 3 * i) % mod;
		else
			f[i] = 0;
		p[i] = fac[i] * f[i] % mod;
		if ((n - i) & 1)
			q[i] = mod - inv[n - i];
		else
			q[i] = inv[n - i];
	}
	sol(p, n, q, n);
	for (int i = 0; i <= n; i++)
		printf("%d ", p[n + i] * inv[i] % mod);
	return 0;
}

