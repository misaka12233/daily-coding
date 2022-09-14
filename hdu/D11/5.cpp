#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
const int maxk = 10000 + 10;
const int mod = 998244353;
int fac[maxn], inv[maxn];
int n, k, x;
ll A[maxk << 2], B[maxk << 2];
ll ans[maxk << 2];

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
				s[i + j + len] = ((x - y) % mod + mod) % mod;
			}
		}
	}
}


void sol()
{
	scanf("%d%d%d", &n, &k, &x);
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= k; i++)
	{
		fac[i] = 1ll * fac[i - 1] * i % mod;
		inv[i] = fastpow(fac[i], mod - 2);
		ans[i] = 0;
	}
	ans[0] = 0;
	lim = 1;
	l = 0;
	while (lim <= 2 * k)
	{
		lim <<= 1;
		l++;
	}
	for (int i = 0; i < lim; i++)
		num[i] = (num[i >> 1] >> 1) | ((i & 1) << (l - 1));
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		ll now = x;
		for (int j = 0; j <= k; j++)
		{
			A[j] = 1ll * ans[j] * inv[j];
			B[j] = 1ll * now * inv[j];
			ans[j] = (ans[j] + now) % mod;
			now = now * a % mod;
		}
		for (int j = k + 1; j < lim; j++) A[j] = B[j] = 0;
		NTT(A, true);
		NTT(B, true);
		for (int j = 0; j < lim; j++)
			A[j] = 1ll * A[j] * B[j] % mod;
		NTT(A, false);
		ll tmp = fastpow(lim, mod - 2);
		for (int j = 0; j < lim; j++)
			A[j] = 1ll * A[j] * tmp % mod;
		for (int j = 0; j <= k; j++)
			ans[j] = (ans[j] + 1ll * A[j] * fac[j] % mod) % mod;
	}
	printf("%lld\n", ans[k]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

