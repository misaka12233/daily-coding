#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 10;
const int mod = 998244353;
int n, a[maxn];
ll f[31][maxn], valid1[maxn], valid2[maxn];
ll mul(ll x, ll y)
{
	return x * y % mod;
}
ll add(ll x, ll y)
{
	return (x + y) % mod; 
}
ll sub(ll x, ll y)
{
	return (x - y + mod) % mod;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for (int b = 0; b < 31; b++)
	{
		ll sum1 = 0, sum2 = 0, p2 = 1 << b;
		for (int i = 1; i <= n; i++)
		{
			sum1 = add(mul(2, sum1), a[i]);
			sum2 = add(mul(2, sum2), sum1);
			if (a[i] & p2)
			{
				valid1[i] = sub(sum1, valid1[i - 1]);
				valid2[i] = sub(sum2, add(mul(2, valid2[i - 1]), valid1[i]));
			}
			else
			{
				valid1[i] = valid1[i - 1];
				valid2[i] = add(mul(2, valid2[i - 1]), valid1[i]);
			}
			f[b][i] = add(f[b][i - 1], mul(a[i], mul(valid2[i], p2)));
		}
		ans = add(ans, f[b][n]);
	}
	printf("%lld\n", ans);
	return 0;
}

