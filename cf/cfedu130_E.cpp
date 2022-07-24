#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
const ll mod = 998244353;
int n;
int x[maxn], y[maxn];
int dis[maxn][maxn];
bool vis[maxn][maxn];
bool canSame[maxn];
int cnt[maxn], m;
int f[maxn][maxn];
ll fac[maxn];
ll my_pow(ll x, int p)
{
	ll res = 1;
	while (p)
	{
		if (p & 1) res = res * x % mod;
		p >>= 1;
		x = x * x % mod;
	}
	return res;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", x + i, y + i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
	for (int i = 1; i <= n; i++)
	{
		int mn = inf;
		for (int j = 1; j <= n; j++)
		{
			if (j == i) continue;
			mn = min(mn, dis[i][j]);
		}
		for (int j = 1; j <= n; j++)
			if (mn == dis[i][j])
				vis[i][j] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		if (canSame[i]) continue;
		canSame[i] = true;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[i][j]) continue;
			if (!vis[j][i]) 
			{
				canSame[i] = false;
				break;
			}
			for (int k = 1; k <= n; k++)
			{
				if (k == i || k == j) continue;
				if ((vis[j][k] && !vis[i][k]) || (!vis[j][k] && vis[i][k]))
				{
					canSame[i] = false;
					break;
				}
			}
			if (!canSame[i]) break;
		}
		if (canSame[i])
		{
			int sum = 1;
			for (int j = 1; j <= n; j++)
			{
				if (!vis[i][j]) continue;
				sum++;
				canSame[j] = true;
			}
			cnt[++m] = sum;
		}
	}
	f[0][0] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			f[i][j] = f[i - 1][j];
			if (j >= cnt[i] - 1)
				f[i][j] = (f[i][j] + f[i - 1][j - cnt[i] + 1]) % mod;
		}
	}
	ll res = 1;
	fac[0] = 1;
	for (ll i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
	for (int i = 1; i <= n; i++)
		res = (res + f[m][i] * my_pow(fac[i], mod - 2) % mod) % mod;
	res = res * fac[n] % mod;
	printf("%lld\n", res);
	return 0;
}

