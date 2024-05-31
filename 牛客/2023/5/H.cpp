#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200 + 10;
const int maxm = 100000 + 10;
int sz[maxm];
int n, m, mxsz;
int dp[maxn][maxn];
int a[maxn], b[maxn];
int f[maxn][maxn][maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", a + i, b + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", sz + i), mxsz = max(mxsz, sz[i]);
	if (m > n)
	{
		for (int i = 1; i <= n; i++)
			sz[i] = sz[m - n + i];
		m = n;
	}
	
	for (int l = 1; l <= n; l++)
	{
		for (int r = l; r <= n; r++)
		{
			for (int i = 1; i <= mxsz; i++)
			{
				f[l][r][i] = f[l][r - 1][i];
				if (i >= a[r])
					f[l][r][i] = max(f[l][r][i], f[l][r - 1][i - a[r]] + b[r]);
			}
		}
	}
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 0; k <= j; k++)
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + f[k + 1][j][sz[i]]);
	
	printf("%d\n", dp[m][n]);
	return 0;
}

