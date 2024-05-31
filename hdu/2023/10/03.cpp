#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 10;
const int mod = 1e9 + 7;
ll fac[maxn];
ll qpow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
int main()
{
	int m = 1000000;
	fac[0] = 1;
	for (int i = 1; i <= m; i++)
		fac[i] = fac[i - 1] * i % mod;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		printf("%lld\n",  fac[n] * fac[k - 1] % mod * qpow(k, n - k) % mod);
	}
	return 0;
}

