#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
const ll mod = 998244353;
int T;
int n;
int a[maxn];
ll dp[maxn][2];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		ll ans = 0;
		dp[0][0] = 1;
		dp[0][1] = 0;
		for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			if (a[i] > 0)
				dp[a[i] - 1][1] = (dp[a[i] - 1][0] + dp[a[i] - 1][1] * 2) % mod;
			dp[a[i] + 1][0] = (dp[a[i]][0] + dp[a[i] + 1][0] * 2) % mod;
			dp[a[i] + 1][1] = dp[a[i] + 1][1] * 2 % mod;
		}
		for (int i = 0; i <= n; i++) ans = (ans + dp[i][0] + dp[i][1]) % mod;
		ans = (ans - 1 + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}

