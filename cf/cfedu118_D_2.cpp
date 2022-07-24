#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
const ll mod = 998244353;
int T;
int n;
int a[maxn];
ll cnt[maxn], dp[maxn], s[maxn], p[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		ll ans = 0;
		for (int i = 0; i <= n; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			dp[i] = cnt[a[i]];
			if (a[i] == 0) dp[i] = (dp[i] + 1) % mod;
			else dp[i] = (dp[i] + cnt[a[i] - 1]) % mod;
			cnt[a[i]] = (cnt[a[i]] + dp[i]) % mod;
			ans = (ans + dp[i]) % mod;
		}
		p[0] = 1;
		for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % mod;
		for (int i = 0; i <= n; i++) s[i] = 0;
		for (int i = n; i >= 1; i--)
		{
			if (a[i] >= 2)
				ans = (ans + cnt[a[i] - 2] * p[s[a[i]] + s[a[i] - 2]] % mod) % mod;
			cnt[a[i]] = (cnt[a[i]] - dp[i] + mod) % mod;
			s[a[i]]++;
		}
		ans = (ans + p[s[1]] - 1 + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}


