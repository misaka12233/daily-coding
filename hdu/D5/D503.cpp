#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
struct node{
	int v;
	ll w;
	node(int v, ll w)
	{
		this->v = v;
		this->w = w;
	}
};
vector<node> e[maxn * 3];
int n, k, s, t;
ll p;
int dep[maxn], mxd;
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	mxd = max(mxd, dep[u]);
	for (auto now : e[u])
	{
		int v = now.v;
		if (v == fa) continue;
		dfs(v, u);
	}
}
ll dis[maxn * 3];
bool vis[maxn * 3];
priority_queue<pli> q;
void dij()
{
	while (!q.empty()) q.pop();
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto now : e[u])
		{
			int v = now.v;
			if (dis[v] > dis[u] + now.w)
			{
				dis[v] = dis[u] + now.w;
				q.push({-dis[v], v});
			}
		}
	}
}
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= 3 * n; i++)
	{
		dis[i] = 1ll * n * inf;
		vis[i] = false;
		e[i].clear();
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		e[u].push_back(node(v, w));
		e[v].push_back(node(u, w));
	}
	mxd = 0;
	dfs(1, 0);
	for (int u = 1; u <= n; u++)
	{
		e[n + dep[u]].push_back(node(u, 0));
		e[u].push_back(node(2 * n + dep[u], 0));
	}
	scanf("%d%lld%d%d", &k, &p, &s, &t);
	for (int i = 1; i + k <= mxd; i++)
	{
		e[2 * n + i].push_back(node(n + i + k, p));
		e[2 * n + i + k].push_back(node(n + i, p));
	}
	dij();
	printf("%lld\n", dis[t]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		sol();
	}
	return 0;
}
/*
2
7
1 2 5
1 3 5
2 4 3
3 5 100
3 6 100
4 7 5
2 1
7 1
6
6 1 2
3 5 2
2 4 6
5 2 2
5 6 20
3 8
6 5
*/
