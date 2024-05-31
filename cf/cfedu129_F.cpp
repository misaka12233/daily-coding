#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
int n, m, T;
struct node{
	node(int x, int y, int val): x(x), y(y), val(val) {}
	node()
	{
		x = y = val = 0;
	}
	int x;
	int y;
	int val;
};
bool vis[maxn];
vector<int> v[maxn];
vector<node> e[maxn];
vector<int> now_e[maxn];
ll siz[maxn], dp[maxn], g[maxn][2];
int st[maxn], top;
int tin[maxn], tout[maxn], dep[maxn], fa_val[maxn], fa[maxn][19];
void dfs(int x)
{
	tin[x] = ++T;
	siz[x] = 1;
	dep[x] = dep[fa[x][0]] + 1;
	for (node a : e[x])
	{
		int y = a.y;
		if (y == fa[x][0]) continue;
		fa[y][0] = x;
		fa_val[y] = a.val;
		dfs(y);
		siz[x] += siz[y];
	}
	tout[x] = T;
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 18; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if (x == y) return x;
	for (int i = 18; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void sol(int x, int val)
{
	dp[x] = g[x][1] = 0;
	g[x][0] = siz[x];
	for (int y : now_e[x])
	{
		sol(y, val);
		dp[x] += dp[y];
		g[x][0] -= siz[y];
	}
	for (int y : now_e[x])
	{
		if (fa_val[y] == val)
		{
			dp[x] += g[y][0] * g[x][0];
			g[x][1] += g[y][0];
		}
		else
		{
			dp[x] += g[y][1] * g[x][0];
			dp[x] += g[y][0] * g[x][1];
			g[x][0] += g[y][0];
			g[x][1] += g[y][1];
		}
	}
}
bool cmp(int x, int y)
{
	return tin[x] < tin[y];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y, val;
		scanf("%d%d%d", &x, &y, &val);
		node a(x, y, val), b(y, x, val);
		e[x].push_back(a);
		e[y].push_back(b);
		v[val].push_back(x);
		v[val].push_back(y);
	}
	dfs(1);
	for (int k = 1; k < 19; k++)
		for (int i = 1; i <= n; i++)
			fa[i][k] = fa[fa[i][k - 1]][k - 1];
	ll ans = 0;
	for (int val = 1; val <= n; val++)
	{
		v[val].push_back(1);
		sort(v[val].begin(), v[val].end(), cmp);
		v[val].erase(unique(v[val].begin(), v[val].end()), v[val].end());
		int m = v[val].size();
		for (int i = 0; i < m; i++)
			vis[v[val][i]] = true;
		for (int i = 0; i < m - 1; i++)
		{
			int x = lca(v[val][i], v[val][i + 1]);
			if (!vis[x])
			{
				vis[x] = true;
				v[val].push_back(x);
			}
		}
		sort(v[val].begin(), v[val].end(), cmp);
		top = 0;
		for (int x : v[val])
		{
			while (top > 0 && (tin[x] < tin[st[top]] || tout[st[top]] < tout[x])) top--;
			if (top > 0)
				now_e[st[top]].push_back(x);
			st[++top] = x;
		}
		sol(1, val);
		ans += dp[1];
		for (int x : v[val])
			vis[x] = false, now_e[x].clear();
	}
	printf("%lld\n", ans);
	return 0;
}

