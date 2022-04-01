#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 10;
int T;
int dp[maxn][maxn];
int n, x;
int a[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 0; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = max(0, dp[i][j - 1] + a[j]);
				if (i >= 1)
					dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 1][j - 1] + a[j] + x));
			}
		}
		for (int i = 0; i <= n; i++)
		{
			int ans = 0;
			for (int j = 1; j <= n; j++)
				ans = max(ans, dp[i][j]);
			printf("%d ", ans);
		}
		puts("");
	}
	return 0;
}

