#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20000 + 10;
const int maxm = 200000 + 10;
int n, m;
struct node{
	int v;
	ll w;
	int nxt;
};
node edge[maxm];
int head[maxn], tot;
int id[maxn], dfn[maxn], low[maxn], tim, cnt;
int sta[maxn], top;
ll dp[maxn];
int deg[maxn];
bool ins[maxn], incir[maxn];
queue<int> q;
void add(int u, int v, ll w)
{
	tot++;
	edge[tot].v = v;
	edge[tot].w = w;
	edge[tot].nxt = head[u];
	head[u] = tot;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++tim;
	sta[++top] = u;
	ins[u] = true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int v = edge[i].v;
		if (!dfn[v])
		{
			tarjan(v);
			low[u ]= min(low[u], low[v]);
		}
		else if (ins[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		int num = 0;
		cnt++;
		while (sta[top] != u)
		{
			id[sta[top]] = cnt;
			ins[sta[top]] = false;
			top--;
			num++;
		}
		id[sta[top]] = cnt;
		ins[sta[top]] = false;
		top--;
		num++;
		incir[cnt] = num > 1;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int u = 1; u <= n; u++)
	{
		if (incir[id[u]])
			printf("%d ", u);
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].v;
			if (id[u] != id[v])
				add(id[u] + n, id[v] + n, edge[i].w), deg[id[v] + n]++;
		}
	}
	putchar('\n');
	for (int i = 1; i <= cnt; i++)
		if (!deg[i+n]) 
			q.push(i + n), dp[i + n] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].v;
			dp[v] = max(dp[v], dp[u] + edge[i].w);
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
	ll ans = 0;
	for (int i = 1; i <= cnt; i++) 
		ans = max(ans, dp[i + n]);
	printf("%lld\n", ans);
}

