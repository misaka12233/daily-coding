#include<bits/stdc++.h>
using namespace std;
const int maxn = 2000000 + 10;
typedef long long ll; 
int n, q;
ll a[maxn];
int f[maxn];
ll g[maxn][20];
// f[x] = cnt of i (a[i]&x == x)
// g[x][b] = sum of 2^b - a[i] % 2^b (a[i]&x == x)
int main()
{
	int m = 1 << 20;
	ll tot = 0;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", a + i);
		f[a[i]]++;
		for (int j = 0, t = 1; j < 20; j++, t <<= 1)
			g[a[i]][j] += t - a[i] % t;
		tot = tot + m - a[i];
	}
	for (int t = 0; t < 20; t++)
	{
		for (int x = 0; x < m; x++)
		{
			if ((x & (1 << t)) == 0)
			{
				f[x] += f[x | (1 << t)];
				for (int b = 0; b < 20; b++)
					g[x][b] += g[x | (1 << t)][b];
			}
		}
	}
	while (q--)
	{
		ll k, ans = 0;
		scanf("%lld", &k);
		if (k >= tot)
		{
			printf("%lld\n", (k - tot) / n + m);
			continue;
		}
		for (int t = 19; t >= 0; t--)
		{
			ll b = 1ll << t;
			ll s = b * (n - f[ans]) + g[ans][t] - g[ans | b][t];
			if (k >= s)
			{
				k -= s;
				ans |= b;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

