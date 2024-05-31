#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
typedef long long ll;
int n;
ll ans;
ll a[maxn];
vector<int> e[maxn];
ll dp[maxn][4];
void dfs(int x, int fa)
{
	for (int i = 1; i <= 3; i++)
		dp[x][i] = -1ll * n * inf;
	for (auto y : e[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		
		ll val = max({dp[y][3] + a[y], dp[y][2] + a[y], dp[y][1], a[y]});
		dp[x][3] = max({dp[x][3], dp[x][3] + val, dp[x][2] + val});
		dp[x][2] = max(dp[x][2], dp[x][1] + val);
		dp[x][1] = max(dp[x][1], val);
	}
	ans = max({ans, dp[x][3] + a[x], dp[x][2], dp[x][1] + a[x], a[x]});
}
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i), e[i].clear();
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans = 0;
	dfs(1, 0);
	printf("%lld\n", ans);
} 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

