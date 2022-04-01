#include<bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
const int mod = 10;
int n, m;
int w[maxn];
int f[maxn][maxn], ans[maxn][maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", w + i);
	for (int i = 1; i <= n; i++)
	{
		f[i - 1][0] = 1;
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = f[i - 1][j];
			if (j >= w[i])
				f[i][j] = (f[i][j] + f[i - 1][j - w[i]]) % mod;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans[i][0] = 1;
		for (int j = 1; j <= m; j++)
		{
			ans[i][j] = f[n][j];
			if (j >= w[i])
				ans[i][j] = (ans[i][j] - ans[i][j - w[i]] + mod) % mod;
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}

