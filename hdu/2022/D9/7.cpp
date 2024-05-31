#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 10;
const int mod = 998244353;
int n, k, r;
int a[maxn];
int dp[maxn][maxn];
void sol()
{
	scanf("%d%d%d", &n, &k, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	int now = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		while (a[now + 1] + r <= a[i]) now++;
		for (int j = 1; j <= i; j++)
			dp[i][j] = (1ll * max(0, j - (i - 1 - now)) * dp[i - 1][j] % mod + dp[i - 1][j - 1]) % mod;
	}
	printf("%d\n", dp[n][k]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

