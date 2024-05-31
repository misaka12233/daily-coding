#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int maxm = 100 + 10;
int n, m;
char s[maxn], f[maxm];
int dp[maxn][maxm];
void sol()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%s", f + 1);
	m = strlen(f + 1);
	int ans = inf, st = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == f[1])
			dp[i][1] = i;
		else
			dp[i][1] = dp[i - 1][1];
		for (int j = 2; j <= i && j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (s[i] == f[j])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
		}
		if (dp[i][m] != 0 && ans > i - dp[i][m] + 1)
		{
			ans = i - dp[i][m] + 1;
			st = dp[i][m];
		}
	}
	for (int i = 0; i < ans; i++)
		printf("%c", s[st + i]);
	printf("\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

