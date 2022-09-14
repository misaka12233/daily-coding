#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 100000 + 10;
int n, k;
int dp[maxn][25];
int fac[maxn], inv[maxn];
int C(int n, int m)
{
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
	scanf("%d%d", &n, &k);
	fac[0] = fac[1] = inv[0] = inv[1] = dp[0][0] = 1;
	for (int i = 2; i <= k; i++)
	{
		fac[i] = 1ll * i * fac[i - 1] % mod;
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
	for (int i = 2; i <= k; i++) 
		inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i][j] = 1ll * i * dp[i - 1][j] % mod;
			for (int l = 0; l < j; l++)
				dp[i][j] = (dp[i][j] + 1ll * C(j, l) * dp[i - 1][l] % mod) % mod;
		}
	}
	printf("%d\n", dp[n][k]);
	return 0;
}

