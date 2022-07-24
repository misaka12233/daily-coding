#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, q;
ll x;
ll w[maxn], sum[maxn];
ll mul(ll a, ll b, ll mod)
{
	ll res = 0;
	a %= mod;
	b %= mod;
	while (b)
	{
		if (b & 1) res = (res + a) % mod;
		b >>= 1;
		a = (a + a) % mod;
	}
	return res;
}
int getnum(ll res)
{
	int l = 0, r = n, mid;
	while (l < r)
	{
		mid = l + r >> 1;
		if (res <= sum[mid]) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main()
{
	scanf("%d%d%lld", &n, &q, &x);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", w + i);
		sum[i] = w[i] + sum[i - 1];
	}
	for (int i = 1; i <= q; i++)
	{
		ll k, res, t, ans;
		scanf("%lld", &k);
		t = getnum(mul(k - 1, x, sum[n]));
		if (x <= sum[n] - sum[t])
			res = x + sum[t], ans = -t;
		else 
			res = x - sum[n] + sum[t], ans = n - t;
		ans = ans + res / sum[n] * n + getnum(res % sum[n]);
		printf("%lld\n", ans);
	}
	return 0;
}

