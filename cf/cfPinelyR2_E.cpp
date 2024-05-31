#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 200000 + 10;
set<ll> ed;
int n, m, k;
int h[maxn];
queue<int> q;
int dp[maxn];
int vis[maxn];
vector<pii> st;
int indeg[maxn];
vector<int> e[maxn];
void dfs(int u, int t)
{
	vis[u] = true;
	ed.erase(1ll * dp[u] * k + h[u]);
	dp[u]++;
	ed.insert(1ll * dp[u] * k + h[u]);
	for (auto v : e[u])
	{
		if (vis[v]) continue;
		if (dp[u] > dp[v] || (dp[u] == dp[v] && h[u] > h[v]))
			dfs(v, t); 
	}
}
void sol()
{
	scanf("%d%d%d", &n, &m, &k);
	st.clear();
	for (int i = 1; i <= n; i++)
	{
		e[i].clear();
		scanf("%d", h + i);
		indeg[i] = dp[i] = vis[i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		e[x].push_back(y);
		indeg[y]++;
	}
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v : e[u])
		{
			indeg[v]--;
			if (indeg[v] == 0)
				q.push(v);
			if (dp[u] > dp[v])
				dp[v] = dp[u];
			if (dp[u] == dp[v] && h[u] > h[v])
				dp[v]++;
		}
	}
	ed.clear();
	for (int i = 1; i <= n; i++)
	{
		ed.insert(1ll * dp[i] * k + h[i]);
		if (dp[i] == 0)
			st.push_back(pii(h[i], i));
	}
	sort(st.begin(), st.end());
	ll ans = *ed.rbegin() - st[0].first;
	for (int i = 1; i < st.size(); i++)
	{
		int t = st[i].first;
		if (!vis[st[i - 1].second])
			dfs(st[i - 1].second, t);
		ans = min(ans, *ed.rbegin() - t);
	}
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

