#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
ll a[maxn], b[maxn];
ll ans, sum, gap[maxn];
bool dp[maxn][maxn * maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld", a + i);
		for (int i = 1; i <= n; i++)
			scanf("%lld", b + i);
		for (int i = 1; i <= n; i++)
		{
			if (a[i] < b[i])
			swap(a[i], b[i]);
		}
		ans = sum = 0;
		for (int i = 1; i <= n; i++)
		{
			gap[i] = a[i] - b[i];
			sum += gap[i];
			for (int j = 1; j < i; j++)
			{
				ans += (a[i] + a[j]) * (a[i] + a[j]);
				ans += (b[i] + b[j]) * (b[i] + b[j]);
			}
		}
		sort(gap + 1, gap + n + 1);
		for (int i = 1; i <= n; i++)
		{
			dp[i - 1][0] = true;
			for (int j = 1; j <= sum; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= gap[i])
				dp[i][j] |= dp[i - 1][j - gap[i]];
			}
		}
		ll now = 0;
		for (int i = sum / 2; i >= 0; i--)
		{
			if (dp[n][i]) 
			{
				now = i;
				break;
			}
		}
		ans -= 2 * now * (sum - now);
		printf("%lld\n", ans);
	}
	return 0;
}

