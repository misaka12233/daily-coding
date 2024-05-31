#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 10 + 10;
const int maxt = 300 + 10;
const int maxs = 1 << 10;
int n, t, k, m;
int x[maxn];
ll pre[maxt];
ll f[maxt][maxn][maxs];
int main()
{
	scanf("%d%d%d%d", &n, &t, &k, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", x + i);
	for (int i = 1; i <= t; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (x[j] == i)
				cnt++;
		pre[i] = pre[i - 1] + cnt;
	}
	f[0][0][0] = 1;
	for (int i = 1; i <= t; i++)
	{
		f[i][0][0] = 1;
		for (int j = 1; j <= pre[i]; j++)
		{
			int state = 1 << k;
			for (int s = 0; s < state; s++)
			{
				if ((s >> i) > 0 && i <= k) continue;
				int cnt = 0;
				for (int l = 0; l < k; l++)
					if ((s & (1 << l)) > 0)
						cnt++;
				if (cnt > m || cnt > j) continue;
				if (s & 1)
				{
					ll tmp = (f[i - 1][j - 1][s >> 1] + f[i - 1][j - 1][(s >> 1) | (state >> 1)]) % mod;
					f[i][j][s] = tmp * (pre[i] - (j - 1)) % mod;
				}
				else
					f[i][j][s] = (f[i - 1][j][s >> 1] + f[i - 1][j][(s >> 1) | (state >> 1)]) % mod;
			}
		}
	}
	ll ans = 0;
	int state = 1 << k;
	for (int s = 0; s < state; s++)
		ans = (ans + f[t][n][s]) % mod;
	printf("%lld\n", ans);
	return 0;
}

