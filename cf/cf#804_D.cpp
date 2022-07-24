#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 10;
int T;
int n, m;
int a[maxn], cnt[maxn];
int dp[maxn];
bool del[maxn][maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) cnt[j] = 0;
			int mx = 0;
			for (int j = i; j <= n; j++)
			{
				cnt[a[j]]++;
				mx = max(mx, cnt[a[j]]);
				if ((j - i + 1) % 2 == 0 && mx * 2 <= j - i + 1)
					del[i][j] = true;
				else
					del[i][j] = false;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (1 > i - 1 || del[1][i - 1]) dp[i] = 1;
			else dp[i] = 0;
			for (int j = 1; j <= i - 1; j++)
				if (dp[j] > 0 && a[j] == a[i] && (j + 1 > i - 1 || del[j + 1][i - 1]))
					dp[i] = max(dp[i], dp[j] + 1);
			if (i + 1 > n || del[i + 1][n]) ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

