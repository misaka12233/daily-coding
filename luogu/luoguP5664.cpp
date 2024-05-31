#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
const int maxm = 2000 + 10;
const int mod = 998244353;
int n, m;
int a[maxn][maxm];
int sum[maxn];
int dp[maxn][maxn << 1];
int ans;
int main()
{
	scanf("%d%d", &n, &m);
	ans = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			sum[i] = (sum[i] + a[i][j]) % mod;
		}
		ans = 1ll * ans * (sum[i] + 1) % mod;
	}
	dp[0][n] = 1;
	for (int k = 1; k <= m; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = n - i; j <= n + i; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j > 0)
					dp[i][j] = (dp[i][j] + 1ll * a[i][k] * dp[i - 1][j - 1] % mod) % mod;
				if (j < 2 * n)
					dp[i][j] = (dp[i][j] + 1ll * (sum[i] - a[i][k] + mod) * dp[i - 1][j + 1] % mod) % mod;
			}
		}
		for (int i = n + 1; i <= 2 * n; i++)
			ans = (ans - dp[n][i] + mod) % mod;
	}
	printf("%d\n", (ans - 1 + mod) % mod);
	return 0;
}

