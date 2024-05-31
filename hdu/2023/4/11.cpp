#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
const int mod = 998244353;
int T;
int n, m;
ll f[maxn][maxn], g[maxn][maxn];
ll ans0, ans1;
void sol()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = 1ll * n * inf, g[i][j] = 0;
	ans0 = 1ll * n * inf, ans1 = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		f[u][v] = w;
		g[u][v] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (f[i][j] > f[i][k] + f[k][j])
				{
					f[i][j] = f[i][k] + f[k][j];
					g[i][j] = g[i][k] * g[k][j] % mod;
				}
				else if (f[i][j] == f[i][k] + f[k][j])
					g[i][j] = (g[i][j] + g[i][k] * g[k][j] % mod) % mod;
			}
		}
		if (ans0 > f[k][k])
		{
			ans0 = f[k][k];
			ans1 = g[k][k];
		}
		else if (ans0 == f[k][k])
			ans1 = (ans1 + g[k][k]) % mod;
	}
	if (ans1 != 0)
		printf("%lld %lld\n", ans0, ans1);
	else
		puts("-1 -1");
}
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

