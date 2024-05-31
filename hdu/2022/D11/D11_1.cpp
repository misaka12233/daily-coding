#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
const int maxval = 1000;
int n, m;
int a[maxn];
int dp[maxn][maxn];
int c[maxval + 10];
int lowbit(int x) { return x & -x; }
int add(int p, int v)
{
	for (int i = p; i <= maxval; i += lowbit(i))
		c[i] += v;
}
int getval(int rk)
{
	int res = 0, cnt = 0;
	for (int i = 10; i >= 0; i--)
	{
		res += (1 << i);
		if (res > maxval || cnt + c[res] >= rk) res -= (1 << i);
		else cnt += c[res];
	}
	return ++res;
}
void sol()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++) dp[0][i] = inf;
	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j <= n; j++)
		{
			dp[i][j] = inf;
			for (int k = j - 1; k >= i - 1; k--)
			{
				int len = j - k;
				add(a[k + 1], 1);
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + getval(len - (int)(0.05 * len)));
			}
			for (int k = j - 1; k >= i - 1; k--)
				add(a[k + 1], -1);
		}
	}
	printf("%d\n", dp[m][n]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

