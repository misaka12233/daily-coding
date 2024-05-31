#include<bits/stdc++.h>
using namespace std;
const int maxn = 400 + 10;
const int mod = 998244353;
int n, m;
int dp[2][maxn][maxn];
void addeq(int &x, int y){ x = (x + y) % mod; }
int main()
{
	scanf("%d%d", &n, &m);
	dp[0][m][0] = 1;
	int now = 1, pre = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k + j <= m; k++)
			{
				dp[now][j][k] = dp[pre][j][k]; // ²»·Å 
				if (k >= 1)
					addeq(dp[now][j][k], 1ll * (j + 1) 			     * dp[pre][j + 1][k - 1] % mod); // 0
				if (j + k + 1 <= m)
				{
					addeq(dp[now][j][k], 1ll * (k + 1)               * dp[pre][j][k + 1]     % mod); // 1
					addeq(dp[now][j][k], 1ll * (j + 1) * k           * dp[pre][j + 1][k]     % mod); // 01
				}
				if (k >= 2)
					addeq(dp[now][j][k], 1ll * (j + 2) * (j + 1) / 2 * dp[pre][j + 2][k - 2] % mod); // 00
				if (j + k + 2 <= m)
					addeq(dp[now][j][k], 1ll * (k + 2) * (k + 1) / 2 * dp[pre][j][k + 2]     % mod); // 11
			}
		}
		now = now ^ 1;
		pre = pre ^ 1;
	}
	int ans = 0;
	for (int i = 0; i <= m; i++)
		for (int j = 0; i + j <= m; j++)
			addeq(ans, dp[pre][i][j]);
	printf("%d\n", ans); 
	return 0;
}

