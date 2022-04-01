#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
const ll mod = 998244353;
int T;
int n, m, k, q, cnt[2], sum;
int x[maxn], y[maxn];
bool vis[2][maxn];
bool all;
ll ksm(ll val, ll pow)
{
	ll ans = 1;
	while (pow)
	{
		if (pow & 1) ans = 1ll * ans * val % mod;
		val = 1ll * val * val % mod;
		pow >>= 1;
	}
	return ans;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &n, &m, &k, &q);
		cnt[0] = cnt[1] = sum = all = 0;
		for (int i = 1; i <= n; i++)
		vis[0][i] = false;
		for (int i = 1; i <= m; i++)
		vis[1][i] = false;
		for (int i = 1; i <= q; i++)
			scanf("%d%d", x + i, y + i);
		for (int i = q; i >= 1; i--)
		{
			if ((vis[0][x[i]] && vis[1][y[i]]) || all) continue;
			sum++;
			if (!vis[0][x[i]])vis[0][x[i]] = true, cnt[0]++;
			if (!vis[1][y[i]]) vis[1][y[i]] = true, cnt[1]++;
			if (cnt[0] == n || cnt[1] == m) all = true;
		}
		printf("%lld\n", ksm(k, sum));
	}
	return 0;
}

