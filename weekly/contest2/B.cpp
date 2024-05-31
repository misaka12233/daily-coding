#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 10;
int n;
int a[maxn];
double dp[maxn][maxn];
int main()
{
	scanf("%d", &n);
	double sum = 0.0;
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), sum = sum + a[i];
	sort(a + 1, a + n + 1);
	dp[1][1] = 1.0;
	dp[2][1] = 0.0;
	dp[2][2] = 1.0;
	for (int m = 3; m <= n; m++)
	{
		dp[m][m] = 1.0;
		for (int i = 1; i < m; i++)
			dp[m][i] = dp[m - 2][i - 1] * (i - 1) / (m - 1) + dp[m - 2][i] * (m - i - 1) / (m - 1);
	}
	double ans = 0.0;
	for (int i = 1; i <= n; i++)
		ans = ans + dp[n][i] * a[i];
	printf("%.9f %.9f", ans, sum - ans);
	return 0;
}

